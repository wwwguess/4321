// Room: /d/village/lakeside.c

inherit ROOM;

void create()
{
	set("short", "���ݺ���");
	set("long", @LONG
���ݺ��Բ������Ͻ����������������Һ���ʢ��ζ�����������㡣
�кܶ�����ۺ��ϣ������㲶��Ϊ�������������Ƕ�վ�ڰ��ߣ������
�ݣ��������ʲô��ʷ��������߻�ɢ���˼���ľ��(boat)��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"lake",
  "east" : __DIR__"road7",
]));
	set("objects",([
		__DIR__"npc/fisher":3,
	]) );
	
	set("item_desc", ([
		"boat":
		"�����ܾ����������洬������Ի���(paddle)���������ġ�
" ]) );
	set("no_clean_up", 0);

	setup();
	//replace_program(ROOM);
}

void init()
{
	add_action("do_paddle", "paddle");
}

int do_paddle(string arg)
{
	if(!arg || arg=="")
		return notify_fail("��Ҫ��ʲô��\n");
	if( arg!="boat" && arg!="��" )
		return notify_fail("���������뻮ʲô��\n");
	message_vision("$N�����洬����������Ļ�ȥ��\n", this_player());
	write("�����ڻ����������ˡ�\n");
	this_player()->move(__DIR__"lake");
	return 1;
}

int valid_leave(object me,string dir)
{
        if( dir=="west" )
            return notify_fail( "��ô���һƬ���������߹�ȥ��\n" );
        return ::valid_leave(me,dir);
}
