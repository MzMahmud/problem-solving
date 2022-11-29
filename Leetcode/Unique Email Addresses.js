const collectToSet = () => [
    (set, string) => {
        set.add(string);
        return set;
    },
    new Set()
];

const getNormalizedEmail = email => {
    const [localName, domainName] = email.split('@');
    const normalizedLocalName = localName.replaceAll(/\+.*/ig, '').replaceAll('.', '');
    return `${normalizedLocalName}@${domainName}`;
}

const numUniqueEmails = emails => emails.map(getNormalizedEmail).reduce(...collectToSet()).size;
