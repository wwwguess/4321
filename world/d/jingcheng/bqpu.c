// Room: /d/jingcheng/bqpu.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[32m������[2;37;0m");
	set("long", @LONG
��һ���žͿ����������ϰ��Ÿ��ֱ��������ϰٽ��صĴ󵶵�����
���ӵķɻ�ʯ����Ӧ�о��С�Ů�ϰ�����Ӣ������Զ��СŮ����Ҳ
����Զ�ھֶ��ϰ壬����������ü��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"dchjie1",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiaoxiao" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
