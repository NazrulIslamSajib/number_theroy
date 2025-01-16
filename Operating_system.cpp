#include<bits/stdc++.h>
using namespace std;
void checkneed(int need[][10], int max[][10], int alloc[][10], int p, int r) {
    for(int i=0;i<p;i++)
    {
        for (int j=0;j<r;j++)
        {
            need[i][j] = max[i][j]-alloc[i][j];
        }
    }
}
bool isSafe(int processes, int resources, int avail[],int max[][10],int alloc[][10]) {
    int need[10][10];
    checkneed(need, max, alloc, processes, resources);
    bool finish[10]={false};
    int safeSeq[10];
    int work[10];
    for (int i=0;i<resources;i++)
    {
        work[i] =avail[i];
    }
    int count = 0;
    while (count < processes)
    {
        bool found=false;
        for (int p=0;p<processes;p++)
        {
            if(!finish[p])
             {
                int j;
                for (j =0;j<resources;j++)
                {
                    if (need[p][j]>work[j])
                    {
                        break;
                    }
                }
                if (j == resources)
                {
                    for (int k = 0; k < resources; k++) {
                        work[k] += alloc[p][k];
                    }
                    safeSeq[count++]=p;
                    finish[p] = true;
                    found = true;
                }
            }
        }
        if(!found)
        {
            cout <<"Not safe state!"<<endl;
            return false;
        }
    }
    cout << "System is in a safe state.\nSafe Sequence: ";
    for (int i = 0; i < processes; i++)
    {
        cout << safeSeq[i];
        if (i != processes - 1)
        {
            cout << " -> ";
        }
    }
    cout << endl;
    return true;
}
void bankers()
{
    cout<<"This is Banker's Algorithm"<<endl;
    cout<<endl;
    int p,r;
    cout<<"Give process Number ";
    cin>>p;
    cout<<"Give Resouce Number ";
    cin>>r;
    int alloc[10][10],max1[10][10], avail[10];
    cout<<"Give the Allocation Matrix:" << endl;
    for(int i = 0; i < p; i++)
    {
        for(int j=0;j<r;j++)
        {
            cin >>alloc[i][j];
        }
    }
    cout<<"Enter the Max Matrix:"<<endl;
    for(int i=0;i<p;i++)
    {
        for (int j=0;j<r;j++)
        {
            cin>>max1[i][j];
        }
    }
    cout<< "Enter the Available Resources: ";
    for (int i = 0; i < r; i++) {
        cin >> avail[i];
    }
    isSafe(p,r,avail,max1,alloc);
}
void FIFO()
{
    int f,p;
    cout<<"Enter the number of frames: ";
    cin>>f;
    cout<<"Enter the number of pages: ";
    cin>>p;
    int pages[p];
    cout<<"Enter the page reference sequence: ";
    for (int i =0;i<p; i++)
    {
        cin>>pages[i];
    }
    queue<int>frameQueue;
    int pageFaults=0;
    bool inMemory[100]={0};
    for (int i = 0;i<p;i++)
    {
        int curpage=pages[i];
        if (!inMemory[curpage])
        {
            if(frameQueue.size()==f)
             {
                int oldestPage=frameQueue.front();
                frameQueue.pop();
                inMemory[oldestPage]=false;
            }
            frameQueue.push(curpage);
            inMemory[curpage]=true;
            pageFaults++;
            cout << "Page "<<curpage<<" caused a page fault." << endl;
        }
        else
        {
            cout<<"Page " <<curpage<<" was already in memory (no page fault)." << endl;
        }
    }
    cout<<endl;
    cout <<"Total Page Faults: " << pageFaults << endl;
}
int findOptimalPage(int frames[],int numFrames,int pages[],int currentIndex,int numPages)
{
    int farthest=currentIndex,pageIndex =-1;
    for(int i=0;i<numFrames; i++)
    {
        int j;
        for (j = currentIndex;j<numPages;j++)
        {
            if(frames[i]==pages[j])
            {
                if(j>farthest)
                {
                    farthest = j;
                    pageIndex = i;
                }
                break;
            }
        }

        if (j == numPages) {
            return i;
        }
    }
    if(pageIndex==-1)
    {
        return 0;
    }
    else
    {
        return pageIndex;
    }
}
void OPTIMAL()
{
     int numFrames, numPages;
    cout << "Enter the number of frames: ";
    cin >> numFrames;

    cout << "Enter the number of pages: ";
    cin >> numPages;

    int pages[numPages];
    cout << "Enter the page reference sequence: ";
    for (int i = 0; i < numPages; i++) {
        cin >> pages[i];
    }
    int frames[numFrames];
    int pageFaults = 0, currentIndex = 0;
    for (int i = 0; i < numFrames; i++) {
        frames[i] = -1;
    }
    for (int i = 0; i < numPages; i++) {
        int currentPage = pages[i];
        bool found = false;
        for (int j = 0; j < numFrames; j++) {
            if (frames[j] == currentPage) {
                found = true;
                break;
            }
        }
        if (!found) {
            if (currentIndex < numFrames) {

                frames[currentIndex++] = currentPage;
            } else {

                int replaceIndex = findOptimalPage(frames, numFrames, pages, i + 1, numPages);
                frames[replaceIndex] = currentPage;
            }

            pageFaults++;
            cout << "Page " << currentPage << " caused a page fault." << endl;
        } else {
            cout << "Page " << currentPage << " was already in memory (no page fault)." << endl;
        }
    }
    cout << "\nTotal Page Faults: " << pageFaults << endl;
}
long long menu()
{

    cout<<"Enter 1 to see the Banker's Algorithm"<<endl;
    cout<<"Enter 2 to see the FIFO"<<endl;
    cout<<"Enter 3 to see the Optimal Page replacement"<<endl;
    cout<<"Enter 0 to Exit"<<endl;
    int type;
    cin>>type;
    system("cls");
    return type;
}
int main()
{
    cout<<endl;
    cout<<"************************ Operating system Lab ***************** " <<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    while(1)
    {
        long long cas=menu();
        if(cas==0)
        {
            cout<<"Thank you "<<endl;
            break;
        }
        else if(cas==1)
        {
            bankers();

        }
        else if(cas==2)
        {
            FIFO();
        }
        else if(cas==3)
        {
            OPTIMAL();
        }
    }


    return 0;
}



