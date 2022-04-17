#include <bits/stdc++.h>
using namespace std;

int intSize = 4;

struct page{
    map<int,int> primaryKey;    //<pk,slotID>
    int currentSize;
    int count;
    page(){
        count = 0;
        currentSize = 4 * intSize;
    }
};

void insert(vector<page> &file, int pk, int size, int max_size){
    if(file.empty()){
        page pg = page();
        pg.currentSize += size;
        pg.primaryKey[pk] = pg.count;
        pg.count++;
        file.push_back(pg);
    }else{
        bool inserted = false;
        for(int i = 0; i<file.size(); i++){
            if(file[i].currentSize + size + intSize <= max_size){
                file[i].currentSize += size;
                file[i].primaryKey[pk] = file[i].count;
                file[i].count++;
                inserted = true;
                break;
            }
        }
        if(!inserted){
            page pg = page();
            pg.currentSize += size;
            pg.primaryKey[pk] = pg.count;
            pg.count++;
            file.push_back(pg);
        }
    }
};

void status(vector<page> file){
    cout << file.size() <<' ';
    for(int i=0; i<file.size(); i++){
        cout << file[i].count << ' ';
    }
    cout << '\n';
};

void search(vector<page> file, int num){
    bool found = false;
    for(int i=0; i<file.size(); i++){
        if(file[i].primaryKey[num]){
            cout << i << " " << file[i].primaryKey[num];
            found = true;
            break;
        }
    }
    if(!found){
        cout << -1 << " " << -1;
    }
    cout << '\n';
};

int main(){
    int maxSize;
    cin >> maxSize;
    vector<page> file;
    int op,num,size;
    while(1){
        cin >> op;
        if(op == 1){
            cin >> size >> num;
            insert(file,num,size,maxSize);
        }else if(op==2){
            status(file);
        }else if(op==3){
            cin >> num;
            search(file,num);
        }else{
            break;
        }
    }
    return 0;
}