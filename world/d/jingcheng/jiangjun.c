// Room: /d/jingcheng/jiangjun.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[1;37m������[2;37;0m");
	set("long", @LONG
    �����ǵ����󽫵Ĺ�ۡ��Ľ�����ΰݵ���Ҳ�ܶࡣ����������
��ͷ�ߴ��ʯʨ�ӡ�������һ�û����������дУ��ڸ��˴���Ժ
�ӣ�����Ժ�������������ġ��ϱ��Ǹ��ճ�������ǽ�������֮�ء�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"jjun2",
  "north" : __DIR__"xw6",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/qinyu" : 1,
]));

	setup();
}

int valid_leave(object me, string dir)
{
	object *inv;
	int i;

	inv = all_inventory(me);
	if( dir == "south" ){
		if( me->query("family/family_name") == "������"
		|| (int)me->query_temp("baishi") == 1
		|| !present( "qin yu", this_object() ) )
		return ::valid_leave(me, dir);
		for( i =sizeof(inv)-1 ; i >=0 ; i -- ){ 
			if( inv[i]->query("id") == "lingpai" ) 
				return ::valid_leave(me, dir);
		}
	return notify_fail(GRN"����һ�������һ�֣���ס��˵����֪"+
	RANK_D->query_respect(me)+"�����������кι�ɰ���(answer)\n"NOR);
	}
	return ::valid_leave(me, dir);
}
