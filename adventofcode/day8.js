const fs = require('node:fs');
const { exit } = require('node:process');
const data = fs.readFileSync('day8.txt','utf8').split('\n')

data.forEach((element,index) => {
    element  = element.trim()
    data[index] = element.split('').map((item)=>parseInt(item))
});
var truth_table = data.map((element)=>{
    return element.slice()
    })
for(let i = 0 ;i < truth_table.length;i++)
    for(let j = 0 ;j < truth_table[i].length;j++)
            truth_table[i][j] = 0
const countf = () =>{
    for(let i = 1;i < data[0].length - 1;i++)
    {
        let max_up = (data[0][i])
        for(let j  = 1;j < data.length - 1;j++)
        {
            var vv = (data[j][i]) 
            if (vv > max_up)
            {
                truth_table[j][i] = 1
                max_up = vv
            }
        }
    }
    for(let i = 1;i < data[0].length - 1;i++)
    {
        let max_down = (data[data.length - 1][i])
        for(let j  = data.length - 2;j >= 1;j--)
        {
            var vv = (data[j][i]) 
            if (vv > max_down)
            {
                truth_table[j][i] = 1
                max_down = vv
            }
        }
    }
    for(let i = 1;i < data.length - 1;i++)
    {
        let max_left = (data[i][0])
        for(let j  = 1;j < data[0].length - 1;j++)
        {
            
            var vv = (data[i][j]) 
            if (vv > max_left)
            {
                truth_table[i][j] = 1
                max_left = vv
            }
        }
    }
    for(let i = 1;i < data.length - 1;i++)
    {
        let max_right = (data[i][data[0].length - 1])
        for(let j  = data[0].length  - 2;j >= 1;j--)
        {
            var vv = (data[i][j]) 
            if (vv > max_right)
            {
                truth_table[i][j] = 1
                max_right = vv
            }
        }
    }
    var counter = 0;
    for(let i = 0 ;i < truth_table.length;i++)
    for(let j = 0 ;j < truth_table[i].length;j++)
            if (truth_table[i][j])
                counter++; 
    console.log(counter + (data[0].length * 2) + ((data.length -2 ) * 2))
}
const part2 = () =>{
    var max = 0;
    for(let i = 0;i <  data.length;i++)
        for(let j = 0;j < data[i].length;j++)
            {
                if(truth_table[i][j] == 0)
                    continue
                var left = 0;       
                for(let dx = j - 1;dx >= 0;dx--)
                    if(data[i][dx] < data[i][j])
                        left++;
                    else
                        {
                            left++;
                            break
                        }   
                var right = 0;       
                for(let dxr = j + 1;dxr < data[i].length;dxr++)
                    if(data[i][dxr] < data[i][j])
                      right++;
                    else
                        {
                            right++;
                            break
                        }   
                var up = 0;       
                for(let dy = i - 1;dy >= 0;dy--)
                    if(data[dy][j] < data[i][j])
                         up++;
                    else
                        {
                            up++;
                            break
                        }   
                var down = 0;       
                for(let dyr = i + 1;dyr < data.length;dyr++)
                    if(data[dyr][j] < data[i][j])
                           down++;
                    else
                       {
                             down++;
                             break   
                       }
                
                max = Math.max(max,(down * left * up * right))
            }
            console.log(max)
}
countf()
part2()