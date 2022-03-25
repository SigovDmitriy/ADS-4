// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int sym = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int k = i + 1; k < len; k++) {
      if (arr[k] + arr[i] == value)
      sym++;
    }
  }
  return sym;
}
int countPairs2(int *arr, int len, int value) {
  int sym = 0;
  for (int i = 0; i < len - 1; i++) {
    if (arr[i] <= value) {
      for (int k = len - 1; k > i; k--) {
        if (arr[i] + arr[k] == value)
          sym++
      }
    }
  }
  return sym;
}
int countPairs3(int *arr, int len, int value) {
  int sym = 0;
  for (int i = 0; i < len - 1; i++) {
    int left = i, right = len;
    while (left < right - 1) {
      int mid = (left + right) / 2;
      if (arr[i] + arr[mid] == value) {
        sym++;
        int k = mid + 1;
        while (arr[i] + arr[k] == value && k < right) {
          sym++;
          k++;
        }
        k = mid - 1;
        while (arr[i] + arr[k] == value && k > left) {
          sym++;
          k--;
        }
        break;
      }
      if (arr[i] + arr[mid] > value)
        right = mid;
      else
        left = mid;
    }
  }
  return sym;
}
