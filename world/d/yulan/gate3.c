
inherit ROOM;

void create()
{
	set("short", "��ɳ�Ǵ��");
	set("long", @LONG
	�������Լ��������������һɫ�Ĵ���ʯ���ɣ���������
	�����߶���Ե�ʣ�һ����̦Ҳû�У�����¶��ʯͷ��ԭɫ��
	�����ǵ����ŵ�·�������ǳ��ǵķ���
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west"  : "/d/maintown/mt_road5",
  "east"  : "/d/yulan/gate2",
]));
        set("no_clean_up", 0);
        
	set("outdoors", "maintown");

	setup();
	replace_program(ROOM);
}

