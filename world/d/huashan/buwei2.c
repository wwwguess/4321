// buwei2.c

inherit ROOM;
int do_push(string);

void create()
{
        set("short", "����");
	set("long", @LONG
����������Ⱥ�����ң�����Ⱥ�ڽ������˳ơ����ӽ���������Ϊһ�������ţ�
����������ȴ���õĺܼ򵥡�����һ�Ŵ�����ֻ���ӣ�ǽ�����Ż�ױ̨��ֻ�п�ǽ
һ�ź�ľ����(desk)���Ե��������ɡ�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"houhuayuan2",
]));
        setup();
	set ("item_desc", ([
		"desk" : 
"����һ�źܽ�ʵ�ĺ�ľ�����������ϰ��ż�ֻ�Ǻ��ʣ�ĥ��һ���ī��\n"
"����һ��δ�õİ�ֽ��\n"
	])  ) ;

        set("no_clean_up", 0);

        setup();
}
void init()
{
        add_action("do_move", "move");
	add_action("do_push", "push");
}

int do_move(string arg)
{
	object paper;
	paper = new(__DIR__"obj/paper");

        if( !arg || arg=="" ) return 0;

        if( arg=="desk" ) {
		if (!query("hs_trigger")){
		message_vision(
"$N��������������������ص������ƺ�����û��...��ͻȻ��������\n"
"ǽ��֮��Ʈ���һ����������ֽ��\n", this_player());
		paper->move(__FILE__);
		set("hs_trigger", 1);
		return 1;
		}
		message_vision(
"$N��������������������ص�������˿������\n", this_player());
		return 1;
	}
	return 0;
}
int do_push(string arg)
{

        if( !arg || arg=="" ) return 0;

        if( arg=="��")
        {
                write("ֻ�����·��������졣\n");
		message("vision", "���������и�����\n", this_player());
                set("exits/down", __DIR__"midao");

                remove_call_out("close");
                call_out("close", 5, this_object());

                return 1;
        }
}

void close(object room)
{
        message("vision","ľ���ƻ�ԭ�ء�\n", room);
        room->delete("exits/down");
}
