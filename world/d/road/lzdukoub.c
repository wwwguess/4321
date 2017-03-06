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
    set("short", "���ݻƺӱ����ɿ�");
    set("long", @LONG
����ǰ���ǲ��η����Ļƺ�(river)���������������۾�����
�����ɴ���������������һ�����������̯����Ҿͽ������ڰ�
�ߡ���������֧һ��ľ�壬���ϰ����˻�������Ļƺ����㡣��ȥ��
Զ���Ǻӿڣ����ٹ����Ͷ�������ȴ��ɴ��ڶɡ�
LONG
    );

    set("exits", ([
                   "northwest" : "/d/road/rdktojyg0.c",
                   "west" : "/d/xingxiu/rqhhtolz2.c",
    ]));

    set("item_desc", ([
        "river" : "��������һҶС�ۣ�Ҳ��(yell)һ�����Ҿ���������\n",
    ]));

    set("outdoors", "road");
    setup();
}


/*�ڴ˸�Ǯ�ڶɻ������*/
/*���ȣ��ɴ����˰�������Ǯ������һ��ߺ�ȣ�������һӿ
 * ���룬СС�ɴ�Ƭ�̼��Խ���������εĺ��������ϱ���
 */
void init()
{
    add_action("do_yell", "yell");
}

void check_trigger()
{
    object room;

    if(!query("exits/enter") ) {
        if( !(room = find_object(__DIR__"lzduchuan")) )
            room = load_object(__DIR__"lzduchuan");
        if( room = find_object(__DIR__"lzduchuan") ) {
            if((int)room->query("yell_trigger")==0 ) {
                room->set("yell_trigger", 1);
                set("exits/enter", __DIR__"lzduchuan");
                room->set("exits/out", __FILE__);
                message("vision", "һҶ���ۻ�����ʻ�˹�����������һ��̤��"
                    "����ϵ̰����Ա�˿�\n���¡�\n", this_object() );
                message("vision", "������һ��̤�Ű���ϵ̰����γ�һ������"
                    "�Ľ��ݡ�\n", room);
                remove_call_out("on_board");
                call_out("on_board", 15);
            }
            else
                message("vision", "ֻ���ý��������������������"
                    "�����æ���š�����\n",this_object() );
        }
        else
            message("vision", "ERROR: boat not found\n", this_object() );
    }
    else
        message("vision", "����һֻ�ɴ��ϵ�������˵�������������أ������ɡ�\n",
            this_object() );
}


void check_trigger_fast()
{
    object room;

    if(!query("exits/fastboat") ) {
        if( !(room = find_object(__DIR__"lzduchuan_fast")) )
            room = load_object(__DIR__"lzduchuan_fast");
        if( room = find_object(__DIR__"lzduchuan_fast") ) {
            if((int)room->query("yell_trigger_fast")==0 ) {
                room->set("yell_trigger_fast", 1);
                set("exits/fastboat", __DIR__"lzduchuan_fast");
                room->set("exits/out", __FILE__);
                message("vision", "һҶ���ۻ�����ʻ�˹�����������һ��̤��"
                    "����ϵ̰����Ա�˿�\n���¡�\n", this_object() );
                message("vision", "������һ��̤�Ű���ϵ̰����γ�һ������"
                    "�Ľ��ݡ�\n", room);
                remove_call_out("on_board_fast");
                call_out("on_board_fast", 5);
            }
            else
                message("vision", "ֻ���ý��������������������"
                    "�����æ���š�����\n",this_object() );
        }
        else
            message("vision", "ERROR: boat not found\n", this_object() );
    }
    else
        message("vision", "����һֻ�촬�ϵ�����˵�������������أ������ɡ�\n",
            this_object() );
}


void on_board()
{
    object room;

    if( !query("exits/enter") ) return;

    message("vision", "������̤�Ű��������������һ�㣬��������ʻȥ��\n",
        this_object() );

    if( room = find_object(__DIR__"lzduchuan") )
    {
        room->delete("exits/out");
        message("vision", "������̤�Ű���������˵��һ��������ඡ���"
            "���һ�㣬������\n����ʻȥ��\n", room );
                                                           }
    delete("exits/enter");

    remove_call_out("arrive");
    call_out("arrive", 15);
}

void on_board_fast()
{
    object room;

    if( !query("exits/fastboat") ) return;

    message("vision", "������̤�Ű��������������һ�㣬��������ʻȥ��\n",
        this_object() );

    if( room = find_object(__DIR__"lzduchuan_fast") )
    {
        room->delete("exits/out");
        message("vision", "������̤�Ű���������˵��һ��������ඡ���"
            "���һ�㣬������\n����ʻȥ��\n", room );
                                                           }
    delete("exits/fastboat");

    remove_call_out("arrive_fast");
    call_out("arrive_fast", 5);
}


void arrive()
{
    object room;
    if( room = find_object(__DIR__"lzduchuan") )
    {
        room->set("exits/out", __DIR__"lzdukoun.c");
        message("vision", "����˵���������ϰ��ɡ����漴��һ��̤�Ű�"
            "���ϵ̰���\n",room );
    }
    remove_call_out("close_passage");
    call_out("close_passage", 10);
}

void arrive_fast()
{
    object room;
    if( room = find_object(__DIR__"lzduchuan_fast") )
    {
        room->set("exits/out", __DIR__"lzdukoun.c");
        message("vision", "����˵���������ϰ��ɡ����漴��һ��̤�Ű�"
            "���ϵ̰���\n",room );
    }
    remove_call_out("close_passage_fast");
    call_out("close_passage_fast", 5);
}

void close_passage()
{
    object room;
    if( room = find_object(__DIR__"lzduchuan") ) {
        room->delete("exits/out");
        message("vision","������̤�Ű����������ѱ���ʻ���ġ�\n", room);
        room->delete("yell_trigger");
    }
}

void close_passage_fast()
{
    object room;
    if( room = find_object(__DIR__"lzduchuan_fast") ) {
        room->delete("exits/out");
        message("vision","������̤�Ű����������ѱ���ʻ���ġ�\n", room);
        room->delete("yell_trigger_fast");
    }
}

int do_yell(string arg)
{
    string dir;

    if( !arg || arg=="" ) return 0;

    if( arg=="boat" ) arg = "����";
    if( arg=="fastboat" ) arg = "���ϴ�"; 
    if( (int)this_player()->query("age") < 16 )
        message_vision("$Nʹ�����̵���������һ������" + arg + "��\n",
            this_player());
    else if( (int)this_player()->query("force") > 500 )
        message_vision("$N���˿�����һ����" + arg + "������������ƽ�͵�ԶԶ��"
            "�˳�ȥ��\n", this_player());
    else
        message_vision("$N������������Хһ������" + arg + "����\n",
            this_player());
    if( arg=="����")
    {
        check_trigger();
        return 1;
    }
    if( arg == "���ϴ�" )
     {
         check_trigger_fast();
         return 1;
     }
    else
        message_vision("������ԶԶ����һ���������" + arg +
            "��������\n", this_player());
    return 1;
}

void reset()
{
    object room;

    ::reset();
    if( room = find_object(__DIR__"lzduchuan") )
        room->delete("yell_trigger");
    if( room = find_object(__DIR__"lzduchuan_fast") )
        room->delete("yell_trigger_fast");

}
