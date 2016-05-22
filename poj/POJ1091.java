package me.lotay.test;

import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;

public class POJ1091 {
	static int n;
	static int m ;
	static BigInteger res = null;
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		n = scanner.nextInt();
		m = scanner.nextInt();
		scanner.close();
		
		
		res = new BigInteger(m+"");
		res = res.pow(n);
		getPrimeNum((int) Math.sqrt(m));
//		for(int i=0;i<primeNumbers.size();i++){
//			System.out.print(primeNumbers.get(i)+"\t");
//		}
		
//		if(m==1){
////			System.out.println(m);
////			return;
//		}
		splitNum(m);
		solve();
//		System.out.println("\n"+numbers);	
		System.out.println(res);
	}
	
	static void select(boolean added,int cnt,int num[],int idx,int ii){
		if(cnt==0){
			long p = 1;
			for(int i=0;i<num.length;i++){
//				System.out.print(num[i]+" ");
				p*=num[i];
			}
			p = m/p;
			BigInteger tmp = new BigInteger(""+p);
			tmp = tmp.pow(n);
			if(added){
				res = res.add(tmp);
			}else
				res = res.subtract(tmp);
			return ;
		}
		for(int i=ii;i<numbers.size();i++){
			num[idx]=numbers.get(i);
			select(added,cnt-1,num,idx+1,i+1);
		}
	}
	
	static void solve(){
		int cnt = 1;
		boolean added = false;
		while(cnt<=numbers.size()){
			int nums[] = new int[cnt];
			select(added,cnt,nums,0,0);
			added = !added;
			cnt++;
		}
	}
	
	static ArrayList<Integer> primeNumbers = new ArrayList<Integer>();
	static ArrayList<Integer> numbers = new ArrayList<Integer>();
	static void getPrimeNum(int m){
		boolean marks[] = new boolean[m];
		primeNumbers.add(2);
		for(int i=3;i<m;i+=2){
			if(!marks[i]){
				primeNumbers.add(i);
				for(int j=2*i;j<m;j+=i){
					marks[j] = true;
				}
			}
		}
	}
	static void splitNum(int m){
		HashSet<Integer> splitedNums = new HashSet<Integer>();
		while(true){
			boolean flag = false;
			for(int i=0;i<primeNumbers.size();i++){
				if(m%primeNumbers.get(i)==0){
					splitedNums.add(primeNumbers.get(i));
					m /= primeNumbers.get(i);
					flag = true;
				}
			}
			if(!flag){
				if(m>1)	splitedNums.add(m);
				break;
			}
		}
		numbers.addAll(splitedNums);
	} 
}
