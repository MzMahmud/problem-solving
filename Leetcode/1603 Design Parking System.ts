class ParkingSystem {
    private spots: number[];

    constructor(big: number, medium: number, small: number) {
        this.spots = [0, big, medium, small];
    }

    addCar(carType: number): boolean {
        if (this.spots[carType] === 0) {
            return false;
        } 
        this.spots[carType]--;
        return true;
    }
}
