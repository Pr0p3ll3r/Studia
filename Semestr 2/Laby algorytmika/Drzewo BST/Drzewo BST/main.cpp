#include <iostream>

using namespace std;

struct node
{
    int key;
    node* parent;
    node* left;
    node* right;
};

bool isEmpty(node* &root)
{
    if(root==nullptr)
        return true;
    else
        return false;
}

node* make_node(int value)
{
    node* n= new node;
    n->key=value;
    n->left=nullptr;
    n->right=nullptr;
    n->parent=nullptr;
    return n;
}

void add_node(int value, node* &root)
{
    if(root==nullptr)
    {
        root=make_node(value);
        return;
    }
    node* temp=root;
    while(true)
    {
        if(value>=temp->key)
        {
            if(temp->right==nullptr)
            {
                temp->right=make_node(value);
                temp->right->parent=temp;
                return;
            }
            else
            {
                temp=temp->right;
            }
        }
        else
        {
            if(temp->left==nullptr)
            {
                temp->left=make_node(value);
                temp->left->parent=temp;
                return;
            }
            else
            {
                temp=temp->left;
            }
        }
    }
}

void preorder(node* root)
{
    if(root!=nullptr)
    {
        cout<<root->key<<endl;
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node* root)
{
    if(root!=nullptr)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->key<<endl;
    }
}

void inorder(node* root)
{
    if(root!=nullptr)
    {
        inorder(root->left);
        cout<<root->key<<endl;
        inorder(root->right);
    }
}

node* find_node(node* root, int value)
{
    while(root!=nullptr)
    {
        if(root->key==value)
        {
            return root;
        }

        if(value>root->key)
        {
            root=root->right;
        }
        else
        {
            root=root->left;
        }
    }
    return nullptr;
}

node* findSuccessor(node* n)
{
    if(n->right!=nullptr)
    {
        n=n->right;
        while(n->left!=nullptr)
        {
            n=n->left;
        }
        return n;
    }
    node* temp=n->parent;
    while(temp!=nullptr && temp->left!=n)
    {
        n=temp;
        temp=temp->parent;
    }
    return temp;
}

void delete_node(node* &root, node* delete_node)
{
    node* temp1=nullptr;
    node* temp2=nullptr;

    if(delete_node->left==nullptr || delete_node->right==nullptr)
    {
        temp1=delete_node;
    }
    else
    {
        temp1=findSuccessor(delete_node);
    }

    if(temp1->left!=nullptr)
    {
        temp2=temp1->left;
    }
    else
    {
         temp2=temp1->right;
    }

    if(temp2!=nullptr)
    {
        temp2->parent=temp1->parent;
    }

    if(temp1->parent==nullptr)
    {
        root=temp2;
    }
    else
    {
        if(temp1==temp1->parent->left)
        {
            temp1->parent->left=temp2;
        }
        else
        {
            temp1->parent->right=temp2;
        }
    }

    if(temp1!=delete_node)
    {
        delete_node->key=temp1->key;
    }
    delete temp1;
}

node* postorderNode(node* root)
{
    if(root!=nullptr)
    {
        postorderNode(root->left);
        postorderNode(root->right);
        return root;
    }
}

int main()
{
    node* tree = nullptr;
    int wybor, klucz;
    for(;;)
    {
        cout<<"MENU"<<endl;
        cout<<"1: Czy drzewo jest puste?"<<endl;
        cout<<"2: Dodanie wezla"<<endl;
        cout<<"3: Czy klucz znajduje sie w drzewie?"<<endl;
        cout<<"4: Wyswietlenie drzewa - preorder"<<endl;
        cout<<"5: Wyswietlenie drzewa - inorder"<<endl;
        cout<<"6: Wyswietlenie drzewa - postorder"<<endl;
        cout<<"7: Usuniecie wezla"<<endl;
        cout<<"8: Usuniecie calego drzewa"<<endl;
        cout<<"9: Koniec programu"<<endl;
        cin>>wybor;
        cout<<endl;
        switch(wybor)
        {
            case 1:
                if(isEmpty(tree))
                {
                    cout<<"Drzewo jest puste"<<endl;
                }
                else
                {
                    cout<<"Drzewo nie jest puste"<<endl;
                }
                break;
            case 2:
                cout<<"Podaj klucz: ";
                cin>>klucz;
                if(find_node(tree, klucz)==nullptr)
                {
                    inorder(tree);
                    add_node(klucz, tree);
                    cout<<"Dodano wezel o wartosci "<<klucz<<endl;
                    inorder(tree);
                }
                else
                {
                    cout<<"Wezel o podanej wartosci klucza istnieje w drzewie"<<endl;
                }
                break;
            case 3:
                cout<<"Podaj klucz: ";
                cin>>klucz;
                if(find_node(tree, klucz)==nullptr)
                {
                    cout<<"Wezel o podanej wartosci klucza nie istnieje w drzewie"<<endl;
                }
                else
                {
                    cout<<"Wezel o podanej wartosci klucza istnieje w drzewie"<<endl;
                }
                break;
            case 4:
                if(isEmpty(tree))
                {
                    cout<<"Drzewo jest puste"<<endl;
                }
                else
                {
                    preorder(tree);
                }
                break;
            case 5:
                if(isEmpty(tree))
                {
                    cout<<"Drzewo jest puste"<<endl;
                }
                else
                {
                    inorder(tree);
                }
                break;
            case 6:
                if(isEmpty(tree))
                {
                    cout<<"Drzewo jest puste"<<endl;
                }
                else
                {
                    postorder(tree);
                }
                break;
            case 7:
                cout<<"Podaj klucz: ";
                cin>>klucz;
                if(find_node(tree, klucz)==nullptr)
                {
                    cout<<"Wezel o podanej wartosci klucza nie istnieje w drzewie"<<endl;
                }
                else
                {
                    inorder(tree);
                    delete_node(tree, find_node(tree, klucz));
                    cout<<"Usunieto wezel o wartosci "<<klucz<<endl;
                    inorder(tree);
                }
                break;
            case 8:
                while(!isEmpty(tree))
                {
                    delete_node(tree, postorderNode(tree));
                }
                break;
            case 9:
                exit(0);
                break;
            default:
                cout<<"Niepoprawny wybor"<<endl;
        }
    }

    return 0;
}
