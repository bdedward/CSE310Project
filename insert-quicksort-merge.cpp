//pseudo code for insertion sort
                                   Running Time
for(j = 2, j < A.length){            n
	int key = A[j];                  n - 1
	i = j - 1;                       n - 1
		while(i > 0 && A[i] > key){  Sum(tj)
			A[i + 1] = A[i];         Sum(tj - 1)
			i = i - 1;               Sum(tj - 1)
		}
	A[i + 1] = key;					 n - 1
}

//pseudo code for quick sort

Quicksort(A[], p, r)
	if(p < r)
		k = Partition(A, p, r)
		Quicksort(A, p, k - 1)
		Quicksort(A, k + 1, r)
		
Partition(A[], p, r){
	x = A[r];
	i = p - 1;
	for(j = p, j < r - 1)
		if(A[j] <= x){
			i = i + 1;
			exchange A[i] and A[j]
		}
	exchange A[i + 1] and A[r]
	return i + 1;
}

//pseudo code for merge sort
merge-sort (A, l, r)
	 if r > l
		m := (r+l)/2
		merge-sort (A, l, m)
		merge-sort (A, m+1, r)
		merge(A, l, m, r)
		
merge (A, l, m, r)
      n1=m-l+1
      n2=r-m
      new L[1..n1+1] and R[1..n2+1]
      L[1..n1]=A[l..m]
      R[1..n2]=A[m+1..r]
      L[n1+1]=inf
      R[n2+1]=inf
      i=1; j=1;
      for k=l to r
         if L[i] <= R[j]
            A[k] = L[i]; i++;
         else
            A[k] = R[j]; j++;
      endfor
		

