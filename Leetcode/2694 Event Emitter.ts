type Callback = (...args: any[]) => any;
type Subscription = {
    unsubscribe: () => void
}

class EventEmitter {
    private callbacksByEventName = new Map<string, Callback[]>();

    subscribe(eventName: string, callback: Callback): Subscription {
        if (!this.callbacksByEventName.has(eventName)) {
            this.callbacksByEventName.set(eventName, []);
        }
        this.callbacksByEventName.get(eventName)!.push(callback);
        return {
            unsubscribe: () => {
                const newCallbacks = this.getCallbacks(eventName).filter(cb => cb !== callback);
                this.callbacksByEventName.set(eventName, newCallbacks);
            }
        };
    }

    emit(eventName: string, args: any[] = []): any[] {
        return this.getCallbacks(eventName).map(callback => callback(...args));
    }

    private getCallbacks(eventName: string) {
        return this.callbacksByEventName.get(eventName) ?? [];
    }
}
