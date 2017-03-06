// Room: /d/city/street3.c

inherit ROOM;

void do_climb (string arg);

void create()
{
        set("short", "��ʦ����");
        set("long", @LONG
���Ǿ�ʦ���ֵ��϶Ρ��������ֶ����ƹ����±���ӡ�����鸮ռ
���ˣ����߱������鸮�Ĵ��ţ��ϱ��������鸮���ʵ�Χǽ(wall)��
��ȥ�ĵ�·һֱͨ����Զ�ܾ֡�
LONG
        );
        set("exits", ([ 
		"east":		__DIR__"shangshu/gate",
		"west":		__DIR__"wumen",
		"north":	__DIR__"street2",
		]));

	set("item_desc", ([
		"wall": (: "һ�θ߸ߵ�Ժǽ�������Ṧ�õ�������(climb)�Ʒ����¡�\n" :),
		]) );

        set("outdoors", "city");

        setup();
}

void init ()
{
	add_action ("do_climb", "climb");
}

void do_climb (string arg)
{
	if ((arg == "wall") || (arg == "up") || (arg == "ǽ")) 
		this_player()->move(__DIR__"wall");
}
	
