inherit ROOM;

void create()
{
	set("short", "����С��");
	set("long", @LONG
�������ѵ�С��ͨ�����Ϸ�, ������һƬï�ܵ�����, С
�������������͵Ĳݵأ�����Ӳݵ��ϴ�������������Ϸ�Ķ�
ͯ�����������ϣ�ʹ�㲻֪������Ų������������
LONG
	);
	set("exits", ([
		"north" :__DIR__"sroad5",
		"southwest" :__DIR__"gate",
	]));

	set("objects", ([
	   "/d/latemoon/npc/butterfly" : 1 ]) );
	set("outdoors", "lateroom");
	setup();
	replace_program(ROOM);
}
