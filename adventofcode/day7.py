ans = 0
ans2 = 40532950
min_removed_one = 40532950-(70000000-30000000)
print(min_removed_one)
def dfs(directory : dict) -> int:
    global ans
    global ans2
    all_directory_content = 0
    for k, v in directory.items():
        if isinstance(v, dict):
            all_directory_content += dfs(v)
        else:
            all_directory_content += v
    if all_directory_content <= 100000:
        ans +=  all_directory_content
    if all_directory_content >= min_removed_one:
        ans2 = min(ans2,all_directory_content)
    return all_directory_content
class Dir:
    def __init__(self,prev = None,current = None):
        self.prev = prev
        self.current = current


filesystem = dict()
filesystem['/'] = dict()
current_dict = Dir(prev=None,current= filesystem['/'])
with open('day7.txt','r') as entry:
    lines = list(map(lambda x: str(x).replace('\n',''),entry.readlines()))
    current_command = 0
    while current_command < len(lines):
        chunked = lines[current_command].split()
        if chunked[1] == 'cd':
            if chunked[2] == '/':
                current_dict = Dir(prev=None,current=filesystem['/'])
            elif chunked[2] == '..':
                if current_dict.prev is None:
                    current_dict = Dir(prev=None,current=filesystem['/'])
                else:
                    current_dict = current_dict.prev
            else:
                new_vis_dir = Dir(prev=current_dict,current=current_dict.current[chunked[2]])
                current_dict = new_vis_dir
            current_command += 1
        else:
            current_command += 1
            while current_command < len(lines) and lines[current_command][0] != '$':
                file_folder = lines[current_command]
                chunked_file = file_folder.split()
                if chunked_file[0] == 'dir':
                    current_dict.current[chunked_file[1]] = dict()
                else:
                    current_dict.current[chunked_file[1]] = int(chunked_file[0])
                current_command += 1

print(dfs(filesystem))
print(ans)
print(ans2)