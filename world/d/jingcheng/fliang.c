// Room: /d/jingcheng/fliang.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[32m�������[2;37;0m");
	set("long", @LONG
����һ��������¡�����ꡣ���ϰ����ڹ�̨����Ц�ݿɾϵؽӴ�
�ſ��ˡ��������һ��ææµµ�ع����š���������޷��ģ���
����������������ϰ��һЩ�㹤����׬һЩǮ��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"zhq9",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/feng" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
