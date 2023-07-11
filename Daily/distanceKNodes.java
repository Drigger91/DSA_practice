package DSA_practice.Daily;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Objects;

public class distanceKNodes {
    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    private boolean preparePath(List<TreeNode> path, TreeNode root, TreeNode target) {
        if (Objects.isNull(root)) return false;
        path.add(root);
        if (root == target || preparePath(path, root.left, target) || preparePath(path, root.right, target)) {
            return true;
        }
        path.remove(root);
        return false;
    }

    private void addNodes(List<Integer> finalResponse, TreeNode src, int k, TreeNode dst) {
        if (Objects.isNull(src) || k < -1 || src == dst) return;
        if (k == -1) {
            finalResponse.add(src.val);
            return;
        }
        addNodes(finalResponse, src.left, k - 1, dst);
        addNodes(finalResponse, src.right, k - 1, dst);
    }

    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        List<TreeNode> path = new ArrayList();
        preparePath(path, root, target);
        for (TreeNode node : path) {
            System.out.print(node.val + " ");
        }
        Collections.reverse(path);
        List<Integer> finalResponse = new ArrayList<>();
        for (int i = 0; i < path.size(); i++) {
            addNodes(finalResponse, path.get(i), k - i, i == 0 ? null : path.get(i - 1));
        }
        return finalResponse;
    }

}
