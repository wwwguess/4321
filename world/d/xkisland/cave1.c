// Room: /u/dunno/cave/cave1.c
//cave: /u/dan/cave/cave1.c
//dan
inherit ROOM;
                                  
void create()
{
	set("short", "����");
	set("long", @LONG
ǧ��Ŷ�,�Ĵ������������.�ı��Ѿ��߲߰���,��ϡ�ɼ���
Щ�Ѻ���.ǽ���������Ͳʻ���һЩ�ֻ�. ����ϸ����
�ǣ����Կ��Ϻ�ӧ....
������һ�������������ֳ��ȣ����ַ��ƣ���̬��������������
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"cave.c",
  "west" : __DIR__"cave2",
  "east" : __DIR__"cave24",
]));
	set("objects", ([ /* sizeof() == 2 */
   __DIR__"npc/npc2":1,
   __DIR__"npc/npc1":1,
]));
	set("no_fight", 1); 
        set("no_sleep_room",1);
        setup();
}

   
void init()
{
	add_action("do_studywall", "studywall");
}

int do_studywall()
{
	object me;  
        float exper;
        me = this_player();
	message_vision("$Nר�ĵ��о�ǽ���ϵ�ͼ�Ρ�\n", me); 
        if ((int)me->query_skill("literate", 1) >= 1)  
                  {
                       tell_object(me, "���ƺ���������Щͼ��!\n");
                  }
        if ((int)me->query_skill("literate", 1) <= 0)
                 {
                       tell_object(me, "�㷢����Щͼ���ƺ����书�й�!\n");
                  }
        if ((int)me->query_skill("force", 1) >= 100
         && (int)me->query_skill("literate", 1) <= 0
               ) 
                {
                        tell_object(me, "��Щ��������˵̫ǳ�ˣ�����\n");
                 }
        if ((int)me->query_skill("force", 1) <= 99
         && (int)me->query_skill("literate", 1) <= 0 
               )       
        	{   
		int force = (int) me->query_skill("force", 1);
          	exper = to_float(me->query("combat_exp")); 
                if( !force || ( pow(to_float(force), 3.0) / 10.0 > exper) )
                  return notify_fail("�㾭�鲻�㣬��ȥ����.\n");
	        	me->receive_damage("gin", 20);
	        	me->improve_skill("force", (me->query("int")));
		        tell_object(me, "��Ļ����ڹ�������ߣ�����\n");
	        }

	return 1;

}
