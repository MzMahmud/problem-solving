function average(salaries: number[]): number {
    let min = salaries[0], max = salaries[0], sum = 0;
    for (const salary of salaries) {
        sum += salary;
        if (salary < min) {
            min = salary;
        }
        if (salary > max) {
            max = salary;
        }
    }
    sum -= (min + max);
    return sum / (salaries.length - 2);
}
