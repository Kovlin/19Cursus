#!usr/bin/python3

from local_lib.path import Path

def try_path():

    d = Path("find_my_file_here")
    d.mkdir_p()
    f = Path(d.name + "/my_file_is_here")
    try:
        f.touch()
        f.open()
        f.write_text("I'm here\n", append=True)
        print(f.text())
    except:
        print("Cannot open the file")

if __name__ == '__main__':
    try_path()
