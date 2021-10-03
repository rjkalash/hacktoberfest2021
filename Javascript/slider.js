const names=[{
    id:1,
    name:'Alex'
},{
    id:2,
    name:'Alex'
},
{
    id:3,
    name:'Alex'
},
{
    id:4,
    name:'Alex'
}]
var start=0

const next=document.getElementById('next')
const prev=document.getElementById('prev')

next.addEventListener('click',()=>{
    start++
    if(start>names.length()-1)
        start=0
})

prev.addEventListener('click',()=>{
    start--
    if(start<0)
    start=names.length()-1
})