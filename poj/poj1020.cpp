int BoxSize;      //���ӳߴ�
int n;            //������ܸ���
int SizeNum[11];  //���ֳߴ�ĵ������
int col[41];      //�Ѻ������зָ��BoxSize*BoxSize��1*1��С��С����
                  //col[i]��¼��i�б�����˵ĸ�����

bool DFS(int FillNum)   //FillNum:�ѷ�����ӵĵ�����
{
    if(FillNum==n)
        return true;

    /*Ѱ�Ҹ�������������ٵ��У���������*/
    int min=50;
    int prow;
    for(int i=1;i<=BoxSize;i++)
        if(min>col[i])
        {
            min=col[i];
            prow=i;
        }

    /*ö�ٸ��ֳߴ�ĵ������¶��ϵط������*/
    for(int size=10;size>=1;size--)
    {
        if(!SizeNum[size])
            continue;

        //���ߴ�Ϊsize�ĵ���������ʱ������ͺ����Ƿ�Խ��
        if(BoxSize-col[prow]>=size && BoxSize-prow+1>=size)
        {
            //�����Ӵӵ�prow�е���prow+size-1�У���size�еĿ��wide��
            //�Ƿ�ÿ��ʣ��Ŀռ䶼�㹻����߶�Ϊsize�ĵ���
            int wide=0;
            for(int r=prow;r<=prow+size-1;r++)
            {
                if(col[r]<=col[prow])  //�Ƚϸ��е�"�����"
                {    //ע�⣬�������Ƚ�"δ�����"BoxSize-col[r]<size��TLE
                    wide++;       //��Ȼ���������ȼۣ���ȷʵ������3�����ң���֪�ι�
                    continue;
                }
                break;
            }

            if(wide>=size)
            {
                int r;
                //����ߴ�Ϊsize�ĵ���
                SizeNum[size]--;
                for(r=prow;r<=prow+size-1;r++)
                    col[r]+=size;
            
                if(DFS(FillNum+1))
                    return true;
 
                //����
                SizeNum[size]++;
                for(r=prow;r<=prow+size-1;r++)
                    col[r]-=size;
            }
        }
    }
    return false;
}

int main(void)
{
    int test;
    cin>>test;
    for(int t=1;t<=test;t++)
    {
		for(int j=0;j<41;j++)col[j]=0;
		for(int j=0;j<11;j++)SizeNum[j]=0;

        cin>>BoxSize>>n;

        int cnt=0;   //��¼size>(BoxSize/2)�ĵ������
        int area=0;  //�������е�������֮��
        for(int i=1;i<=n;i++)
        {
            int size;
            cin>>size;
            area+=size*size;
            SizeNum[size]++;

            if(size>BoxSize/2)
                cnt++;
        }

        if(cnt>1 || area!=BoxSize*BoxSize)
        {
            cout<<"HUTUTU!"<<endl;
            continue;
        }

        if(DFS(0))
            cout<<"KHOOOOB!"<<endl;
        else
            cout<<"HUTUTU!"<<endl;
    }
    return 0;
}
