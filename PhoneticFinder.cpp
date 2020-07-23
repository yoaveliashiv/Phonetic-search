#include "FamilyTree.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

namespace family {
    node *Tree::search(string key, node *leaf) {
        if (leaf != NULL) {
            if (key.compare(leaf->name) == 0) {
                return leaf;
            }
            node *b = search(key, leaf->left);
            if (b != NULL)
                return b;
            else
                return search(key, leaf->right);
        } else {
            return NULL;
        }
    }

    node *Tree::search2(string key, node *leaf) {
        if (leaf != NULL) {
            if (relation(leaf->name).compare(key) == 0) {
                return leaf;
            }
            node *b = search2(key, leaf->left);
            if (b != NULL)
                return b;
            else
                return search2(key, leaf->right);
        } else {
            return NULL;
        }
    }
    node *Tree::search3(node *node1) {
        if (node1 == NULL) return NULL;

        /* first delete both subtrees */
        search3(node1->left);
         search3(node1->right);

        /* then delete the node */
      //  cout << "\n Deleting node: " << node1->data;
        delete node1;
        node1=NULL;
        return NULL;
    }


    void Tree::display() {
        inorder_print(root);
        cout << "\n";
    }

    void Tree::inorder_print(node *leaf) {
        if (leaf != NULL) {
            inorder_print(leaf->left);
            cout << leaf->name << ",";
            inorder_print(leaf->right);
        }
    }

    void Tree::postorder_print() {
        postorder_print(root);
        cout << "\n";
    }

    void Tree::postorder_print(node *leaf) {
        if (leaf != NULL) {
            inorder_print(leaf->left);
            inorder_print(leaf->right);
            cout << leaf->name << ",";
        }
    }

    void Tree::preorder_print() {
        preorder_print(root);
        cout << "\n";
    }

    void Tree::preorder_print(node *leaf) {
        if (leaf != NULL) {
            cout << leaf->name << ",";
            inorder_print(leaf->left);
            inorder_print(leaf->right);
        }
    }

    Tree &Tree::addFather(string sun, string father) {
        node *x = new node;
        x->type = "right";
        x->name = father;
        x ->nameS=sun;
        node *y = search(sun, root);
        if(y==NULL)
            throw std::out_of_range{"The tree cannot handle the '" + sun + "' relationf11"};
        if(y->right!=NULL)
            throw std::out_of_range{"The tree cannot handle the '" + sun + "' relationf22"};
        y->right = x;
        x->parent = y;
        x->right=NULL;
        x->left=NULL;
        return *this;
    }

    Tree &Tree::addMother(string sun, string mother) {
        node *x = new node;
        x->type = "left";
        x->name = mother;
        x ->nameS=sun;
        node *y = search(sun, root);
        if(y->left!=NULL)
            throw std::out_of_range{"The tree cannot handle the '" + sun + "' relation11"};
        if(y->left!=NULL)
            throw std::out_of_range{"The tree cannot handle the '" + sun + "' relation22"};
        y->left = x;
        x->parent = y;
        x->right=NULL;
        x->left=NULL;
        return *this;
    }
    string Tree::dad(string name,bool type) {
        node *b;
        string ans;
        string relation1 = relation(name);
        cout << relation1 + "xxxxxxxxxx";
//        if (relation1.compare("father") == 0)
//            return root->name;
//        if (relation1.compare("mother") == 0)
//            return root->name;
//        if (relation1.compare("grandfather") == 0)
//            ans = find("father");
//        b = search(ans, root);
//        if (type)
//            if (b->left->name.compare(name) != 0)
//                return find2(ans, b->name);
//            else if (b->right->name.compare(name) != 0)
//                return find2(ans, b->name);
//        if (relation1.compare("grandmother") == 0)
//            ans = find("mother");
//        b = search(ans, root);
//        if (type)
//            if (b->left->name.compare(name) != 0)
//                return find2(ans, b->name);
//            else if (b->right->name.compare(name) != 0)
//                return find2(ans, b->name);
//        ans = relation1.substr(6);
//        cout << ans + "xxxxxxxxxx";
//        ans = find(ans);
//        node *u = search(ans, root);
//
//        if (type) {
//            if (u->left == NULL || u->left->name.compare(name) != 0)
//                return find2(ans, u->name);
//        } else {
//        if (u->right == NULL || u->right->name.compare(name) != 0)
//            return find2(ans, u->name);
//    }
      return "" ;


    }
    string Tree::relation(string name) {
        node *b = search(name, root);
        if (b == NULL)
            return "unrelated";
        if (b->name.compare(me) == 0)
            return "me";
        bool type;
        if (b->type.compare("left") == 0)
            type = true;
        else
            type = false;
        int count = 0;
        while (b->name.compare(me) != 0) {
            count++;
            b = b->parent;
        }
        if (type && count == 1)
            return "mother";
        if (type && count == 2)
            return "grandmother";
        if (type && count > 2) {
            string ans = "grandmother";
            while (count > 2) {
                ans = "great-" + ans;
                count--;
            }
            return ans;
        }
        if (!type && count == 1)
            return "father";
        if (!type && count == 2)
            return "grandfather";
        if (!type && count > 2) {
            string ans1 = "grandfather";
            while (count > 2) {
                ans1 = "great-" + ans1;
                count--;
            }
            return ans1;
        }
        return NULL;
    }

    string Tree::find2(string relation,string name) {

        return "ans->name";
    }
    string Tree::find(string relation) {
        node *ans = search2(relation, root);
        if (ans == NULL)
            throw std::out_of_range{"The tree cannot handle the '" + relation + "' relation"};
        return ans->name;
    }
    void Tree::remove(string name) {
        try {


            if (name.compare(me) == 0) {
                root = NULL;
                return;
            }
            node *s = search(name, root);
            bool type;
            if (s->type.compare("left") == 0)
                type = true;
            else
                type = false;

            string sun = s->nameS;
            cout << "   caught exception:" + sun << endl;

            node *d = search(sun, root);

            if (type) {
                node *B = search3(d->left);
                d->left = NULL;
            } else {
                node *B = search3(d->right);
                d->right = NULL;
            }
        }
            catch (exception &ex) {
                cout << "   caught exceptionffff"<< endl;
            }


    }
}
