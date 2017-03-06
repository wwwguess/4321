// Room: /d/choyin/s_gate.c

inherit ROOM;

void create()
{
	set("short", "�����س�����");
	set("long", @LONG
�����������سǵ����ţ��������������ʮ����ǰ�ؽ��ģ���˺�
���ϰ߲��Ķ�������������ȣ������Ե�Ư����࣬����������������
�����ţ�ƽ�յ����ɵ�ȻҲ�ڿ�Щ�������س�������ס������ϴ���ˮ
��³��������֮��Ǩ����ũ�������Ȼ���˳��ţ��ֵ���Ȼ��������
��������һ��������ǽ�Ľֵ������Ծ���������������ǣ����ߵĽֵ�
������ǽͨ���½�����վ������������෿����ũ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"north" : __DIR__"crossroad",
		"east" : __DIR__"dragon_temple",
	        "south" :__DIR__"spath",  
           ]));
	set("objects", ([
		__DIR__"npc/cityguard": 2
	]) );
	set("outdoors", "choyin");

	setup();
	replace_program(ROOM);
}
