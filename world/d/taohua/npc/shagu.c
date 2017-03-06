// shagu.c 傻姑
#include <ansi.h>
inherit NPC;
int tell_test();
string ask_me();
int accept(string);
void create()
{
        set_name("傻姑", ({ "sha gu", "sha", "gu" }));
        set("long", "她一付傻头傻脑的样子，看着你傻傻的笑着。\n");
        set("title", "桃花岛弟子");
        set("gender", "女性");
        set("age", 25);

        set_skill("unarmed", 40);
        set_skill("dodge", 40);
        set_skill("parry", 40);
	set_skill("qimen-bagua",50);
        set("combat_exp", random(40000));
        set("chat_chance",20);
        set("chat_msg", ({ 
                "傻姑呆呆说道：除了杨兄弟，谁还肯陪我捉迷藏啊。\n",
                "傻姑呆呆说道：除了杨兄弟，谁还肯陪我捉迷藏啊。\n",
                "傻姑呆呆说道：除了杨兄弟，谁还肯陪我捉迷藏啊。\n",
                "傻姑呆呆说道：除了杨兄弟，谁还肯陪我捉迷藏啊。\n",
                "傻姑呆呆说道：除了杨兄弟，谁还肯陪我捉迷藏啊。\n",
                "祖师爷爷给了我一本观于奇门八卦的书，我对谁也不说。\n"
        }) );
        set("inquiry", ([
                "捉迷藏":(: tell_test:),
                "micang" : (: tell_test:),
                "奇门八卦":(: ask_me:),  
        ]) );

        setup();
}
void init()
{
       ::init();
        add_action("do_accept","accept");
}         
string ask_me()
{    
  object me,hook;
  me=this_player();
          
        if (query_temp("mark/gived")) return "我已经把书弄丢了，你千万不要让祖师爷知道!";
	if (!(me->query_temp("mark/micang2"))) return "再陪我玩一会吧。";
                        set_temp("mark/gived",1);
			hook = new(__DIR__"obj/bagua.c");
                        hook->move(me);
                        return "祖师爷爷说这本书不能随便给人，好兄弟别说是我给你的。";
                        me->delete_temp("mark/micang2");
         }
int tell_test()
{
        object  me;

        me = this_player(); 
	if (!(present("sha gu",environment()) )  ) return 0;
	if(!(query_temp("mark/micang")))
	{
        command("say 好啊好啊，我最喜欢捉迷藏了。好兄弟，你陪我玩。");
        command("say 杨过兄弟和我玩时，赢家可以向输家提一个问题。现在也一样么？（accept yes/no）" );
        me->set_temp("mark/micang",1);
        }
        else
        {
        command( "say 好兄弟，你陪我玩。" );
        }
        return 1;
} 


int do_accept(string arg)
{
    object feng;
    object me; 
    me=this_player();

    if (!(present("sha gu",environment(me)) )  ) return 0;

    if (!arg || (arg!= "yes" && arg !="no")) return 0;
    if (me->is_fighting()) return 0;
    if (!(me->query_temp("mark/micang"))) return 0;
    if (arg=="yes")
    {
        command("say 好兄弟，你先抓我。");
        message_vision( YEL "$N偷偷将蒙眼布揭开一角！\n" NOR,me);
        message_vision(  "$N故意先左右乱跑一阵，突然猛地一跳,将傻姑抓住。\n" NOR,me);
	me->set_temp("mark/micang2",1);
    }
    else
    {
        command("say 好兄弟，你先抓我。");
        message_vision( YEL "$N偷偷将蒙眼布揭开一角！\n" NOR,me);
        message_vision(  "$N故意先左右乱跑一阵，突然猛地一跳,将傻姑抓住。\n" NOR,me);

    }

    return 1;
}
void reset()
{
    delete_temp("mark/been_get");
}
