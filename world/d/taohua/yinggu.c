// Room: /d/taohua/yinggu.c
//write by lysh
inherit ROOM;

void create()
{
	set("short", "���þ�");
	set("long", @LONG
���������þ�����ֻ����ǰһ�ų������������
��յ�ƣ��ڳ������֮�Ρ�����ϸɳ���ƺ�д��ʲô��
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
 
  "north" : __DIR__"zhaozhe",
       ]));                                                  
       set("item_desc", ([
                "ground": "�����ﲻ֪������������֮ʣ��������֮��֮ʣ��������֮��֮ʣ�������Ｘ�Σ�(think)\n",
                "����": "�����ﲻ֪������������֮ʣ��������֮��֮ʣ��������֮��֮ʣ�������Ｘ�Σ�(think)\n",
           ]));
	set("no_clean_up", 0);

	setup();
	
}


 void init()
{
        add_action("do_think","think");
}
int do_think(string arg)
{ object me;
  int i;
  me=this_player(); 
  i=(int)me->query_skill("qimen-bagua",1);
  if (i<68) return notify_fail("����˼���룬��ôҲ�벻������\n");
  if (i>=68 && i<71) {i=i+1;
                      me->set_skill("qimen-bagua",i);
                      return notify_fail("����˼����,����ͻȻһ�������˴𰸡�\n");
                      }
  if (i>70) return notify_fail("����̫���ˡ�\n");
  return 1;
