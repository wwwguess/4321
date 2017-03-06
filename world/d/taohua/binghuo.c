// Room: /d/island/binghuo.c
//write by lysh

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
��Χ�б�ɽ���ں���,�����и����ɽ�ڲ�ʱ���緢��
�����ž����˳ơ���ëʨ����лѷ����֮������̲
����һ�����ʯ���������һ�ѵ�����Զ����һƬ��
�֣������������˵�ˮ����
LONG
        );
    set("item_desc", ([
                "blade": "����������Ҫ����������pick����ѵ���\n",
                "��": "����������Ҫ����������pick����ѵ���\n",
                "trees": "��Щ�����ÿ��ԣ�cut����������ľ����\n",
                "����" : "��Щ�����ÿ��ԣ�cut����������ľ����\n"
               ]));
        setup();
}

void init()
{
 add_action("do_pick","pick");
 add_action("do_cut","cut");
 add_action("do_swim","swim");
 }

int do_pick(string arg)
{
        object me,blade;
        me=this_player();
        if(!arg) return notify_fail("pick <����>\n");
        if(query_temp("mark/been_get")) return notify_fail("���ѱ������ˡ�\n");
        if((arg == "blade"||arg == "������") && me->query_str()>22 && me->query("force")>500)
 {
                        message_vision( "\n$N�������������������˳�����\n",this_player());
                        blade=new(__DIR__"obj/dragonblade.c");
                        blade->move(me); 
			me->set("marks/blade",1);
                        set_temp("mark/been_get",1);
                        return 1;
                }
        message_vision( "\n$N��������,������������˿������\n",this_player());
        
        return 1;
}   
int do_cut(string arg)
{
      object me;
      me=this_player();
      if(!arg) return notify_fail("cut ʲô\n");
      if(arg == "trees"||arg == "����")
{     message_vision("$N�����������˸�ľ����\n",me);
      if ((present("blade", me))&&(me->query("dex")<25))
        {message_vision("���ų��صĵ����ϲ���СС��ľ��!\n",me);
         me->move(__DIR__"mufa");
         return 1;
        }
      else
        {message_vision("$N����һԾ������ľ����\n",me);
         me->move(__DIR__"mufa");          
        return 1;
         }
}          

} 
int do_swim(string arg)
{
  object me;
  me=this_player();
  if((present("blade",me)))
    {message_vision("���ų��صĵ���$N�����λ��һ�����\n",me);
     return 1;
    }
  else
   {message_vision("$N����������ӿ�Ĵ󺣡�\n",me); 
   me->move(__DIR__"hai2");
   return 1;
   }
}
void reset()
{
    ::reset();
        delete_temp("mark/been_get");
    
}
