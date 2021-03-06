// Room: /d/shaolin/hanshui1.c
// Date: YZC 96/01/19

inherit ROOM;

void check_trigger();
void check_trigger_fast();
void on_board_fast();
void on_board();
void arrive_fast();
void arrive();
void close_passage_fast();
void close_passage();
int do_yell(string);
void reset();


void create()
{
    set("short", "济南府黄河北岸渡口");
    set("long", @LONG
你面前就是波涛翻滚的黄河(river)。浊流滚滚，万舟竞发。
两岸渡船来来往往，江边一长溜摆满了鱼摊，渔家就将船泊在岸
边。几个破萝支一块木板，板上摆满了活蹦乱跳的黄河鲤鱼。过去不
远，是河口，不少过江客都在这里等待渡船摆渡。
LONG
    );

    set("exits", ([
                   "north" : __DIR__"rdktojd3",
    ]));

    set("item_desc", ([
        "river" : "近岸处有一叶小舟，也许喊(yell)一声船家就能听见。\n",
    ]));

    set("outdoors", "road");
    setup();
}


/*在此付钱摆渡或买鱼吃*/
/*（等）渡船靠了岸，付了钱，船家一声吆喝，客人们一涌
 * 而入，小小渡船片刻间便越过波澜涛涛的汉江，靠上北岸
 */
void init()
{
    add_action("do_yell", "yell");
}

void check_trigger()
{
    object room;

    if(!query("exits/enter") ) {
        if( !(room = find_object(__DIR__"jnduchuan")) )
            room = load_object(__DIR__"jnduchuan");
        if( room = find_object(__DIR__"jnduchuan") ) {
            if((int)room->query("yell_trigger")==0 ) {
                room->set("yell_trigger", 1);
                set("exits/enter", __DIR__"jnduchuan");
                room->set("exits/out", __FILE__);
                message("vision", "一叶扁舟缓缓地驶了过来，艄公将一块踏脚"
                    "板搭上堤岸，以便乘客\n上下。\n", this_object() );
                message("vision", "艄公将一块踏脚板搭上堤岸，形成一个向上"
                    "的阶梯。\n", room);
                remove_call_out("on_board");
                call_out("on_board", 10);
            }
            else
                message("vision", "只听得江面上隐隐传来：“别急嘛，"
                    "这儿正忙着呐……”\n",this_object() );
        }
        else
            message("vision", "ERROR: boat not found\n", this_object() );
    }
    else
        message("vision", "岸边一只渡船上的老艄公说道：正等着你呢，上来吧。\n",
            this_object() );
}


void check_trigger_fast()
{
    object room;

    if(!query("exits/jnduchuan_fast") ) {
        if( !(room = find_object(__DIR__"jnduchuan_fast")) )
            room = load_object(__DIR__"jnduchuan_fast");
        if( room = find_object(__DIR__"jnduchuan_fast") ) {
            if((int)room->query("yell_trigger_fast")==0 ) {
                room->set("yell_trigger_fast", 1);
                set("exits/fastboat", __DIR__"jnduchuan_fast");
                room->set("exits/out", __FILE__);
                message("vision", "一叶扁舟缓缓地驶了过来，艄公将一块踏脚"
                    "板搭上堤岸，以便乘客\n上下。\n", this_object() );
                message("vision", "艄公将一块踏脚板搭上堤岸，形成一个向上"
                    "的阶梯。\n", room);
                remove_call_out("on_board_fast");
                call_out("on_board_fast", 5);
            }
            else
                message("vision", "只听得江面上隐隐传来：“别急嘛，"
                    "这儿正忙着呐……”\n",this_object() );
        }
        else
            message("vision", "ERROR: boat not found\n", this_object() );
    }
    else
        message("vision", "岸边一只渡船上的老艄公说道：正等着你呢，上来吧。\n",
            this_object() );
}


void on_board()
{
    object room;

    if( !query("exits/enter") ) return;

    message("vision", "艄公把踏脚板收了起来，竹篙一点，扁舟飞快的向江心驶去。\n",
        this_object() );

    if( room = find_object(__DIR__"jnduchuan") )
    {
        room->delete("exits/out");
        message("vision", "艄公把踏脚板收起来，说了一声“坐稳喽”，"
            "竹篙一点，扁舟向\n江心驶去。\n", room );
                                                           }
    delete("exits/enter");

    remove_call_out("arrive");
    call_out("arrive", 8);
}

void on_board_fast()
{
    object room;

    if( !query("exits/fastboat") ) return;

    message("vision", "艄公把踏脚板收了起来，竹篙一点，扁舟向江心驶去。\n",
        this_object() );

    if( room = find_object(__DIR__"jnduchuan_fast") )
    {
        room->delete("exits/out");
        message("vision", "艄公把踏脚板收起来，说了一声“坐稳喽”，"
            "竹篙一点，扁舟向\n江心驶去。\n", room );
                                                           }
    delete("exits/fastboat");

    remove_call_out("arrive_fast");
    call_out("arrive_fast", 5);
}


void arrive()
{
    object room;
    if( room = find_object(__DIR__"jnduchuan") )
    {
        room->set("exits/out", __DIR__"jndukoun.c");
        message("vision", "艄公说“到啦，上岸吧”，随即把一块踏脚板"
            "搭上堤岸。\n",room );
    }
    remove_call_out("close_passage");
    call_out("close_passage", 10);
}

void arrive_fast()
{
    object room;
    if( room = find_object(__DIR__"jnduchuan_fast") )
    {
        room->set("exits/out", __DIR__"jndukoun.c");
        message("vision", "艄公说“到啦，上岸吧”，随即把一块踏脚板"
            "搭上堤岸。\n",room );
    }
    remove_call_out("close_passage_fast");
    call_out("close_passage_fast", 5);
}

void close_passage()
{
    object room;
    if( room = find_object(__DIR__"jnduchuan") ) {
        room->delete("exits/out");
        message("vision","艄公把踏脚板收起来，把扁舟驶向江心。\n", room);
        room->delete("yell_trigger");
    }
}

void close_passage_fast()
{
    object room;
    if( room = find_object(__DIR__"jnduchuan_fast") ) {
        room->delete("exits/out");
        message("vision","艄公把踏脚板收起来，把扁舟驶向江心。\n", room);
        room->delete("yell_trigger_fast");
    }
}

int do_yell(string arg)
{
    string dir;

    if( !arg || arg=="" ) return 0;

    if( arg=="boat" ) arg = "船家";
    if( (int)this_player()->query("age") < 16 )
        message_vision("$N使出吃奶的力气喊了一声：“" + arg + "”\n",
            this_player());
    else if( (int)this_player()->query("force") > 500 )
        message_vision("$N吸了口气，一声“" + arg + "”，声音中正平和地远远传"
            "了出去。\n", this_player());
    else
        message_vision("$N鼓足中气，长啸一声：“" + arg + "！”\n",
            this_player());
    if( arg=="船家")
    {
        check_trigger();
        return 1;
    }
    if( arg == "fastboat" )
     {
         check_trigger_fast();
         return 1;
     }
    else
        message_vision("江面上远远传来一阵回声：“" + arg +
            "～～～”\n", this_player());
    return 1;
}

void reset()
{
    object room;

    ::reset();
    if( room = find_object(__DIR__"jnduchuan") )
        room->delete("yell_trigger");
    if( room = find_object(__DIR__"jnduchuan_fast") )
        room->delete("yell_trigger_fast");

}
