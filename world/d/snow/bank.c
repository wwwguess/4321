// bank.c

inherit BANK;

void create()
{
	set("short", "����Ǯׯ");
	set("long", @LONG
����һ�������Թ�ƽ�������Ƶ�Ǯׯ��Ǯׯ���ϰ廹�Ǹ������й�
���˵Ķ����ˣ�����Կ���Ǯׯ�������ⶼ��ɨ��ǬǬ������һ������
�����������ڹ�̨���棬��̨�Ϸ���һ������(sign)��������ͨ��ѩͤ
���ֵĴ��š�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : "/d/snow/mstreet1",
]));

	set("objects", ([
 		"/d/snow/npc/annihir" : 1,
              "/d/snow/npc/old-qian":1 ,             
 ]) );






	set("item_desc", ([
		"sign": @TEXT
������Ǯׯ��Ŀǰ�����ṩ�ķ����У�

convert     �һ�Ǯ�ҡ�
 check      ���ʡ�      
 cun        ��Ǯ��
 qu         ȡǮ��
TEXT
	]) );
//    set("no_fight", 1);
//    set("no_magic", 1);
	setup();
}
