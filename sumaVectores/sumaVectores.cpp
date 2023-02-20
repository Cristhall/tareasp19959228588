   #include<iostream>
using namespace std;


int main()
{
    int vec[5] = {1,2,3,4,5};
    int vec2[5]={1,2,3,4,5};
    int vec3[5];

    for(int i=0; i<5; i++)
    {
        vec3[i]=vec[i] + vec2[i];
    }
    for(int i=0; i<5; i++)
    {
        cout << vec3[i] << endl;
    }


return 0;
}
