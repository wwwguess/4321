
// Room: /d/new_taohua/taijie1.c

inherit ROOM;

void create()
{
	set("short", "����ͥ");
	set("long", @LONG
�����ǰ��һ��ʯͤ���к���������ͤ����Զ�����沨��������۹�Ƭ
Ƭ����ʱ�к��紵���������Ŀ�������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */  
  "southwest": __DIR__"taijie1",
  ]));


	setup();
	replace_program(ROOM);
}
