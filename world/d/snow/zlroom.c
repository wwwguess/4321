// Room: /d/snow/guestroom.c

inherit ROOM;

void create()
{
	set("short", "�����������");
	set("long", @LONG
�����Ǵ�����ݵ����������õ��൱���£����аڷ���һ�ź�ľԲ����
������ľԲ�ʣ����һ�������г������µĵط����Ӵ����������������ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : "/d/snow/schoolhall",
]));
	set("objects",
		([
		   CLASS_D("swordsman")+"/zhanglao1":1,
		   CLASS_D("swordsman")+"/zhanglao2" : 1
]) );	
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
