// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25

inherit ROOM;

void create()
{
	set("short","��С��");
	set("long", @LONG
����һ��ɽ��С��,·��խ,�������ϵ�ɽ�����˹���
��һ��С��,��֪���Ǹ�ʲô�õ�.
LONG
	);

	set("exits", ([
		"westup" :__DIR__"shanjiao9",
                "southdown" :__DIR__"shanjiao7",
	]));
	
	set("outdoors", "heimuya");
	setup();
}

