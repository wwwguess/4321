inherit ROOM;

void create()
{
        set("short", "卧室");
        set("long", @LONG
这是一间漂亮的卧室，卧室正中放着一张象牙宝床，床上挂着粉红的
床帐，床沿边镶着钻石，床边放着两盆盆栽的万年松盆景，向南是大
厅。
LONG
        );
        set("exits", ([
                "south" : __DIR__"yulanhall",
        ]));
        set("item_desc", ([
                "宝床": "这个宝床上放着一条锦被，——宝床上一点灰尘也没有。( 宝床 )\n"
        ]) );

        setup();
}

void init()
{
        add_action("do_push", "push");
}

void check_trigger()
{
        object room;

        if( (int)query("left_trigger")==3
        &&      (int)query("right_trigger")==5
        &&      !query("exits/down") ) {
                message("vision", 
"地板忽然发出轧轧的声音，一块地面缓缓移动著，露出一个向下的阶梯。\n",
                        this_object() );
                set("exits/down", __DIR__"secrect");
                if( room = find_object(__DIR__"secrect") ) {
                        room->set("exits/up", __FILE__);
                        message("vision", 
"天花板忽然发出轧轧的声音，露出一个向上的阶梯。\n",
                                room );
                }
                delete("left_trigger");
                delete("right_trigger");
                call_out("close_passage", 10);
        }
}

void close_passage()
{
        object room;

        if( !query("exits/down") ) return;
        message("vision", 
"地板忽然发出轧轧的声音，一块地面缓缓移动著，将向下的通道盖住了。\n",
                this_object() );
        if( room = find_object(__DIR__"secrect") ) {
                room->delete("exits/up");
                message("vision", 
"天花板忽然发出轧轧的声音，向上的阶梯又缓缓地收了回去。\n",
                        room );
        }
        delete("exits/down");
}


int do_push(string arg)
{
        string dir;

        if( !arg || arg=="" ) return 0;

        if( arg=="宝床" ) {
                write("你试著推动这个宝床，似乎可以左右滑动....\n");
                return 1;
        }
        if( sscanf(arg, "宝床 %s", dir)==1 ) {
                if( dir=="right" ) {
                        
message_vision("$N将宝床往右推...，忽然「喀」一声宝床又移回原位。\n", 
this_player());
                        add("right_trigger", 1);
                        check_trigger();
                        return 1;
                } else if( dir=="left" ) {
                        
message_vision("$N将宝床往左推...，忽然「喀」一声宝床又移回原位。\n", 
this_player());
                        add("left_trigger", 1);
                        check_trigger();
                        return 1;
                } else {
                        write("你要将宝床推向那个方向？\n");
                        return 1;
                }
        }
}


void reset()
{
        ::reset();
        delete("left_trigger");
        delete("right_trigger");
}
 
