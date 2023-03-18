type Optional<T> = T | null;

class BrowserHistoryNode {
    url: string;
    prev: Optional<BrowserHistoryNode>;
    next: Optional<BrowserHistoryNode>;

    constructor(url: string, prev: Optional<BrowserHistoryNode>, next: Optional<BrowserHistoryNode>) {
        this.url = url;
        this.prev = prev;
        this.next = next;
    }
}

class BrowserHistory {
    curr: Optional<BrowserHistoryNode>;

    constructor(homepage: string) {
        this.curr = new BrowserHistoryNode(homepage, null, null);
    }

    visit(url: string): void {
        this.curr = this.curr.next = new BrowserHistoryNode(url, this.curr, null);
    }

    back(steps: number): string {
        let nSteps = 0;
        while(this.curr.prev != null && nSteps < steps) {
            this.curr = this.curr.prev;
            nSteps++;
        }
        return this.curr.url;
    }

    forward(steps: number): string {
        let nSteps = 0;
        while(this.curr.next != null && nSteps < steps) {
            this.curr = this.curr.next;
            nSteps++;
        }
        return this.curr.url;
    }
}
