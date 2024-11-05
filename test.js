const str = "#..Q.$Q...$...Q$.Q..$$#.Q..$...Q$Q...$..Q.$$";
let arr=str.split('#')
arr=arr.filter((ele)=>(ele!=''))
let lines=arr[0].split('$').filter((ele)=>(ele!=''))
console.log(lines);

//hello
