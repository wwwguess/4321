// Room: /d/taohua/yaopinfang.c

inherit ROOM;

void create()
{
	set("short", "ҩƷ��");
	set("long", @LONG
����ҩ�����죬������ϵ��ϣ��������������ҩ���Լ����СС��ƿ
�����޶����׶���������һ����������С�����ҩ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */  
  "south" : __DIR__"zhuangbeiku",
  "north": __DIR__"wuqiku",
 
]));
set("objects", ([
		CLASS_D("taohua") + "/yapu.c" : 1,
          __DIR__"npc/di-zi2" : 3,
	]));
	       

	setup();

}
