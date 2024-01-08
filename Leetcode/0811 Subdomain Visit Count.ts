function subdomainVisits(cpdomains: string[]) {
    const visitsBySubdomain = new Map<string, number>();
    for (const cpdomain of cpdomains) {
        const [visit, domain] = cpdomain.split(" ");
        for (const subdomain of getSubDomains(domain)) {
            const visits = (visitsBySubdomain.get(subdomain) ?? 0) + Number(visit);
            visitsBySubdomain.set(subdomain, visits);
        }
    }
    const visits: string[] = [];
    for (const [subdomain, visit] of visitsBySubdomain) {
        visits.push(`${visit} ${subdomain}`);
    }
    return visits;
}

function getSubDomains(domain: string) {
    const parts = domain.split(".");
    let subdomains: string[] = [];
    for (let i = parts.length - 1; i >= 0; i--) {
        const suffix = subdomains.at(-1);
        if (suffix == null) {
            subdomains.push(parts[i]);
        } else {
            subdomains.push(`${parts[i]}.${suffix}`);
        }
    }
    return subdomains;
}
