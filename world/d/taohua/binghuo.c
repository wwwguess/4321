// Room: /d/island/binghuo.c
//write by lysh

inherit ROOM;

void create()
{
        set("short", "冰火岛");
        set("long", @LONG
周围有冰山浮于海上,岛上有个活火山在不时的喷发。
这里大概就是人称“金毛狮王”谢逊避身之所。海滩
旁有一块大岩石，上面插着一把刀。不远处有一片树
林，传来叮叮咚咚的水声。
LONG
        );
    set("item_desc", ([
                "blade": "看起来你需要运足内力（pick）这把刀。\n",
                "刀": "看起来你需要运足内力（pick）这把刀。\n",
                "trees": "这些树正好可以（cut），来座个木筏。\n",
                "树林" : "这些树正好可以（cut），来座个木筏。\n"
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
        if(!arg) return notify_fail("pick <东西>\n");
        if(query_temp("mark/been_get")) return notify_fail("刀已被拿走了。\n");
        if((arg == "blade"||arg == "屠龙刀") && me->query_str()>22 && me->query("force")>500)
 {
                        message_vision( "\n$N运起内力，屠龙刀拔了出来。\n",this_player());
                        blade=new(__DIR__"obj/dragonblade.c");
                        blade->move(me); 
			me->set("marks/blade",1);
                        set_temp("mark/been_get",1);
                        return 1;
                }
        message_vision( "\n$N运足内力,可是屠龙刀稳丝不动。\n",this_player());
        
        return 1;
}   
int do_cut(string arg)
{
      object me;
      me=this_player();
      if(!arg) return notify_fail("cut 什么\n");
      if(arg == "trees"||arg == "树林")
{     message_vision("$N把树砍倒做了个木筏。\n",me);
      if ((present("blade", me))&&(me->query("dex")<25))
        {message_vision("拿着沉重的刀，上不了小小的木筏!\n",me);
         me->move(__DIR__"mufa");
         return 1;
        }
      else
        {message_vision("$N纵身一跃，上了木筏。\n",me);
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
    {message_vision("拿着沉重的刀，$N不能游回桃花岛。\n",me);
     return 1;
    }
  else
   {message_vision("$N跳进波涛汹涌的大海。\n",me); 
   me->move(__DIR__"hai2");
   return 1;
   }
}
void reset()
{
    ::reset();
        delete_temp("mark/been_get");
    
}
