// Room: /d/village/melonguard.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ��é���̶���������ܵ����ӣ�ƽʱ��ũ�������￴�Źϵأ�
���ǵľ����Զ��ܸߣ����з紵�ݶ����ᾯ���������ϵ��ڹ���ı��棬
�������߾����˴����С·�������ܿ����������ϲƵ�լԺ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"melonfarm",
  "northwest" : __DIR__"road7",
]));
	set("objects",([
		__DIR__"npc/meloner":3,
	]) );
	
	set("no_clean_up", 0);

	setup();
}
