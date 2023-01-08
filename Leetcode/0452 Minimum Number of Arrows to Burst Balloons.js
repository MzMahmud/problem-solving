function findMinArrowShots(points) {
    return points.sort((a, b) => a[1] - b[1])
                 .reduce(getArrowsShotMaxEnd, {arrowsShot: 1, maxEnd: points[0][1]})
                 .arrowsShot;
}

function getArrowsShotMaxEnd({arrowsShot, maxEnd}, point) {
    if(maxEnd < point[0]) {
        ++arrowsShot;
        maxEnd = point[1];
    }
    return {arrowsShot, maxEnd};
}
