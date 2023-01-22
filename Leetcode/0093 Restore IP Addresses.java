import java.util.Optional;

class Solution {
    private final List<String> allValidIps = new ArrayList<>();
    
    public List<String> restoreIpAddresses(String s) {
        allValidIps.clear();
        populateAllValidIps(0, s, new ArrayList<>());
        return allValidIps;
    }

    private void populateAllValidIps(int index, String s, List<Integer> dotIndices) {
        if(dotIndices.size() == 3 || index == s.length() - 1) {
            getValidIp(s, dotIndices).ifPresent(ip -> allValidIps.add(ip));
            return;
        }
        dotIndices.add(index + 1);
        populateAllValidIps(index + 1, s, dotIndices);
        dotIndices.remove(dotIndices.size() - 1);

        populateAllValidIps(index + 1, s, dotIndices);
    }

    private boolean isValidIpPart(String ipPart) {
        if(ipPart.length() == 1) {
            return true;
        }
        if(ipPart.length() > 3) {
            return false;
        }
        if(ipPart.startsWith("0")) {
            return false;
        }
        int ipNumber = Integer.parseInt(ipPart);
        return ipNumber <= 255;
    }

    private Optional<String> getValidIp(String s, List<Integer> dotIndices) {
        if(dotIndices.size() != 3) {
            return Optional.empty();
        }
        String[] ipParts = new String[4];
        for(int i = 0; i <= dotIndices.size(); ++i) {
            int startIndex = i == 0 ? 0 : dotIndices.get(i - 1);
            int endIndex = i == dotIndices.size() ? s.length() : dotIndices.get(i);
            ipParts[i] = s.substring(startIndex, endIndex);
            if(!isValidIpPart(ipParts[i])) {
                return Optional.empty();
            }
        }
        return Optional.of(String.join(".", ipParts));
    }
}
