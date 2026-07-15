let problemsData = [];
let statsData = {};
let platformChart = null;
let difficultyChart = null;

// DOM Elements
const syncTimeEl = document.getElementById('last-sync-time');
const statTotalEl = document.getElementById('stat-total');
const statLeetcodeEl = document.getElementById('stat-leetcode');
const statGfgEl = document.getElementById('stat-gfg');
const statHackerRankEl = document.getElementById('stat-hackerrank');
const tbodyEl = document.getElementById('problems-tbody');
const searchInput = document.getElementById('search-input');
const platformFilter = document.getElementById('platform-filter');
const difficultyFilter = document.getElementById('difficulty-filter');
const showingTextEl = document.getElementById('showing-text');

// Helper to normalize GFG difficulty
function normalizeDifficulty(platform, diff) {
    const d = diff.trim().capitalize ? diff.trim().capitalize() : diff.trim();
    if (platform.toLowerCase() === "geeksforgeeks") {
        if (["School", "Basic", "Easy"].includes(d)) return "Easy";
        if (d === "Medium") return "Medium";
        if (["Hard", "Expert"].includes(d)) return "Hard";
    }
    return d;
}

// Animate numbers counting up
function animateNumber(element, target, duration = 1000) {
    if (!element) return;
    let start = 0;
    const stepTime = Math.max(Math.floor(duration / Math.max(target, 1)), 15);
    const step = Math.ceil(target / (duration / stepTime));
    
    const timer = setInterval(() => {
        start += step;
        if (start >= target) {
            element.textContent = target;
            clearInterval(timer);
        } else {
            element.textContent = start;
        }
    }, stepTime);
}

// Load dashboard data
async function loadData() {
    try {
        if (typeof dashboardData === 'undefined') {
            throw new Error('dashboardData is not loaded. Please run sync_readme.py.');
        }
        
        problemsData = dashboardData.problems || [];
        statsData = dashboardData.stats || {};
        
        // Update headers
        syncTimeEl.textContent = dashboardData.last_updated || 'N/A';
        
        // Populate stats cards with animation
        animateNumber(statTotalEl, statsData.total || 0);
        animateNumber(statLeetcodeEl, statsData.leetcode?.total || 0);
        animateNumber(statGfgEl, statsData.geeksforgeeks?.total || 0);
        animateNumber(statHackerRankEl, statsData.hackerrank?.total || 0);
        
        // Render charts
        renderCharts();
        
        // Render problems table
        filterAndRenderTable();
        
    } catch (error) {
        console.error('Error loading dashboard data:', error);
        tbodyEl.innerHTML = `<tr><td colspan="8" class="no-results">❌ Error loading problems database. Ensure you run <code>python scripts/sync_readme.py</code> first to generate the stats.</td></tr>`;
    }
}

// Render Charts
function renderCharts() {
    const platformCtx = document.getElementById('platformChart').getContext('2d');
    const difficultyCtx = document.getElementById('difficultyChart').getContext('2d');
    
    // Destroy previous charts if they exist
    if (platformChart) platformChart.destroy();
    if (difficultyChart) difficultyChart.destroy();
    
    // Platform Doughnut
    const lc = statsData.leetcode?.total || 0;
    const gfg = statsData.geeksforgeeks?.total || 0;
    const hr = statsData.hackerrank?.total || 0;
    const topics = statsData.topics?.total || 0;
    
    platformChart = new Chart(platformCtx, {
        type: 'doughnut',
        data: {
            labels: ['LeetCode', 'GeeksforGeeks', 'HackerRank', 'Topics/Others'],
            datasets: [{
                data: [lc, gfg, hr, topics],
                backgroundColor: [
                    'rgba(255, 161, 22, 0.75)',
                    'rgba(41, 141, 70, 0.75)',
                    'rgba(46, 200, 102, 0.75)',
                    'rgba(56, 189, 248, 0.75)'
                ],
                borderColor: [
                    '#ffa116',
                    '#298d46',
                    '#2ec866',
                    '#38bdf8'
                ],
                borderWidth: 1.5,
                hoverOffset: 12
            }]
        },
        options: {
            responsive: true,
            maintainAspectRatio: false,
            plugins: {
                legend: {
                    position: 'bottom',
                    labels: {
                        color: '#94a3b8',
                        font: { family: 'Plus Jakarta Sans', size: 12 },
                        padding: 15
                    }
                }
            }
        }
    });
    
    // Difficulty Bar Chart (Easy, Medium, Hard)
    // Gather difficulties from leetcode, gfg, hackerrank, and topics
    const difficulties = { Easy: 0, Medium: 0, Hard: 0 };
    
    const platforms = ['leetcode', 'geeksforgeeks', 'hackerrank', 'topics'];
    platforms.forEach(p => {
        if (statsData[p]) {
            difficulties.Easy += statsData[p].Easy || 0;
            difficulties.Medium += statsData[p].Medium || 0;
            difficulties.Hard += statsData[p].Hard || 0;
        }
    });
    
    difficultyChart = new Chart(difficultyCtx, {
        type: 'bar',
        data: {
            labels: ['Easy', 'Medium', 'Hard'],
            datasets: [{
                label: 'Problems Solved',
                data: [difficulties.Easy, difficulties.Medium, difficulties.Hard],
                backgroundColor: [
                    'rgba(16, 185, 129, 0.7)',
                    'rgba(245, 158, 11, 0.7)',
                    'rgba(239, 68, 68, 0.7)'
                ],
                borderColor: [
                    '#10b981',
                    '#f59e0b',
                    '#ef4444'
                ],
                borderWidth: 1.5,
                borderRadius: 6
            }]
        },
        options: {
            responsive: true,
            maintainAspectRatio: false,
            plugins: {
                legend: { display: false }
            },
            scales: {
                y: {
                    grid: { color: 'rgba(255, 255, 255, 0.05)' },
                    ticks: { color: '#94a3b8', stepSize: 1, beginAtZero: true }
                },
                x: {
                    grid: { display: false },
                    ticks: { color: '#94a3b8' }
                }
            }
        }
    });
}

// Filter and render table
function filterAndRenderTable() {
    const query = searchInput.value.toLowerCase().trim();
    const platformVal = platformFilter.value;
    const difficultyVal = difficultyFilter.value;
    
    const filtered = problemsData.filter(p => {
        // Search filter
        const matchQuery = !query || 
            p.title.toLowerCase().includes(query) || 
            (p.id && p.id.toString().includes(query)) ||
            (p.tags && p.tags.some(tag => tag.toLowerCase().includes(query)));
            
        // Platform filter
        const matchPlatform = !platformVal || 
            (platformVal === "Topics" && !["leetcode", "geeksforgeeks", "hackerrank"].includes(p.platform.toLowerCase())) ||
            (platformVal !== "Topics" && p.platform.toLowerCase() === platformVal.toLowerCase());
            
        // Difficulty filter
        const normDiff = normalizeDifficulty(p.platform, p.difficulty);
        const matchDifficulty = !difficultyVal || normDiff.toLowerCase() === difficultyVal.toLowerCase();
        
        return matchQuery && matchPlatform && matchDifficulty;
    });
    
    // Update Showing text
    showingTextEl.textContent = `Showing ${filtered.length} of ${problemsData.length} problems`;
    
    // Render Rows
    if (filtered.length === 0) {
        tbodyEl.innerHTML = `<tr><td colspan="8" class="no-results">🔍 No matching problems found.</td></tr>`;
        return;
    }
    
    tbodyEl.innerHTML = filtered.map(p => {
        const idStr = p.id || '-';
        const normDiff = normalizeDifficulty(p.platform, p.difficulty);
        const diffClass = normDiff.toLowerCase();
        const platClass = p.platform.toLowerCase().replace(" ", "");
        
        // Tags pills HTML
        const tagsHtml = (p.tags || []).map(tag => `<span class="tag-pill">${tag}</span>`).join('');
        
        // Languages HTML
        const langsHtml = (p.languages || []).map(l => `<span class="lang-badge">${l}</span>`).join('');
        
        // Solution local link
        const localLink = `../${p.path}/`;
        
        // External link icon if exists
        const extLinkHtml = p.url ? `
            <a href="${p.url}" target="_blank" class="ext-btn" title="View on ${p.platform}">
                <svg viewBox="0 0 24 24" width="14" height="14" fill="none" stroke="currentColor" stroke-width="2"><path d="M18 13v6a2 2 0 0 1-2 2H5a2 2 0 0 1-2-2V8a2 2 0 0 1 2-2h6M15 3h6v6M10 14L21 3"/></svg>
            </a>
        ` : '';

        return `
            <tr>
                <td><strong>${idStr}</strong></td>
                <td>
                    <span style="font-weight: 600;">${p.title}</span>
                    ${extLinkHtml}
                </td>
                <td><span class="platform-badge ${platClass}">${p.platform}</span></td>
                <td><span class="difficulty-badge ${diffClass}">${p.difficulty}</span></td>
                <td><div style="display:flex; flex-wrap:wrap; max-width: 250px;">${tagsHtml}</div></td>
                <td>${langsHtml}</td>
                <td><span style="color:var(--text-secondary); font-size:0.85rem;">${p.solved_date || '-'}</span></td>
                <td>
                    <a href="${localLink}" target="_blank" class="view-btn">View</a>
                </td>
            </tr>
        `;
    }).join('');
}

// Add event listeners for filters
searchInput.addEventListener('input', filterAndRenderTable);
platformFilter.addEventListener('change', filterAndRenderTable);
difficultyFilter.addEventListener('change', filterAndRenderTable);

// Initialize
document.addEventListener('DOMContentLoaded', loadData);
