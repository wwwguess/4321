// Room: /d/village/road6.c

inherit ROOM;

void roadgone();

void create()
{
	set("short", "��ʯС·");
	set("long", @LONG
��ʯС·�����ﵽ�˾�ͷ����ï�ܵ�é��(grass)��ס��ȥ·��һ��
���紵����Ʈ�������㣬����������ܴ�ĺ��������ϵ�ˮ��ӳ������
��Ⱥɽ����ӰӰ�´¡�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"road5",
]));
	set("item_desc",([
		"grass":"�߸ߵ�é�ݣ����Բ���(pushaside)��\n",
	]) );
	
	set("no_clean_up", 0);

	setup();
	//replace_program(ROOM);
}

void init()
{
	add_action("do_pushaside","pushaside");
}

int do_pushaside(string arg)
{
	if( !arg || arg=="" )
		return notify_fail("���벦��ʲô��\n");
	if( arg!="grass" )
		return notify_fail("����ֻ�вݿ��Բ�����\n");
	set("exits/west",__DIR__"valley2");
	message_vision("$N����é�ݣ�������һ��������·��\n",this_player() );
	call_out("roadgone",5);
	return 1;
}

void roadgone()
{
	if( !query("exits/west") ) return;
	message("vision","é�ݻ��˻Σ�����ס��������·��\n",this_object() );
	delete("exits/west");
}


