const MOD = 1_000_000_007;

function countRoutes(locations: number[], start: number, finish: number, fuel: number): number {
    const n = locations.length;
    const cache = Array.from({ length: n }, _ => new Array<number>(fuel + 1).fill(-1));
    function nRoutes(currCity: number, finish: number, remainingFuel: number): number {
        if (remainingFuel < 0) {
            return 0;
        }
        if (cache[currCity][remainingFuel] !== -1) {
            return cache[currCity][remainingFuel];
        }
        let routes = currCity == finish ? 1 : 0;
        for (let nextCity = 0; nextCity < locations.length; nextCity++) {
            if (nextCity === currCity) {
                continue;
            }
            const fuelLeft = remainingFuel - Math.abs(locations[currCity] - locations[nextCity]);
            routes = (routes + nRoutes(nextCity, finish, fuelLeft)) % MOD;
        }
        return cache[currCity][remainingFuel] = routes;
    }
    return nRoutes(start, finish, fuel);
}
