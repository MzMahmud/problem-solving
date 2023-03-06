class ParkingSystem:
    def __init__(self, big: int, medium: int, small: int):
        self.cars = [0, big, medium, small]

    def addCar(self, carType: int) -> bool:
        if self.cars[carType] == 0:
            return False
        self.cars[carType] -= 1
        return True
