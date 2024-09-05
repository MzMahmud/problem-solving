const dirs = [[0, 1], [1, 0], [0, -1], [-1, 0]] as const;

function robotSim(commands: number[], obstacles: number[][]): number {
    const obstacleSet = new Set<string>();
    for (const obstacle of obstacles) obstacleSet.add(`${obstacle}`);
    let dirIdx = 0, pos: [number, number] = [0, 0], maxDistSq = 0;
    for (const command of commands) {
        if (command == -1) {
            dirIdx = (dirIdx + 1) % 4;
            continue;
        }
        if (command == -2) {
            dirIdx = (dirIdx + 3) % 4;
            continue;
        }
        for (let step = 0; step < command; step++) {
            const nextPos: [number, number] = [
              pos[0] + dirs[dirIdx][0], 
              pos[1] + dirs[dirIdx][1],
            ];
            if (obstacleSet.has(`${nextPos}`)) break;
            pos = nextPos;
        }
        maxDistSq = Math.max(maxDistSq, pos[0] * pos[0] + pos[1] * pos[1]);
    }
    return maxDistSq;
}
