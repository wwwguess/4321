// Room: /d/snow/secrect_storage.c

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
������һ��խС�����ң������ǰֻ��һ���ƾɵ�С��(bed)��һ
ЩǬ�ݡ�
LONG
	);
	set("objects", ([
		__DIR__"obj/shield": 1
	]) );

	setup();
	replace_program(ROOM);
}
