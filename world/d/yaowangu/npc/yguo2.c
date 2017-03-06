//yguo2.c        
//by dwolf 
//97.11.9

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_me();
void heal();

void create()
{
        set_name("���", ({ "yang guo", "yang" }));
       set("nickname", GRN "���" NOR+RED "����" NOR);

        set("long",
                "�����Ǵ���������������������˳�����\n"
                "��һ���ɸɾ����Ļ�ɫ���ۡ�\n"
                "�������ʮ�����ң���Ŀ��࣬��ɫ���ء�\n");
        set("title",YEL "����" NOR);
        set("gender", "����");
        set("age", 42);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 100);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
            set("chat_chance", 100);
        set("chat_msg", ({
                (: heal :),
        }));

        set("max_kee", 10000);
        set("max_gin", 5000);
        set("force", 10000);
        set("max_force", 10000);
        set("force_factor", 100);
        set("combat_exp", 3000000);
        set("score", 1000000);

        set("chat_chance", 100);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "sword.wujian" :),
                (: exert_function , "powerup" :)
        }) );

        set_skill("force", 300);
        set_skill("anran-zhang",200);
        set_skill("jiuyin", 300);
	set_skill("move", 200);
        set_skill("dodge", 210);
        set_skill("zhuifeng-liushi", 210);
           set_skill("strike", 200);
        set_skill("gumu-xinfa",150);
        set_skill("parry", 210);
        set_skill("sword", 250);
      set_skill("xuantie-jianfa", 250);
      set_skill("literate", 100); 
      set_skill("hama-gong",100);
      set_skill("staff",100);
      set_skill("dagou-bang",100);
        map_skill("force", "jiuyin");
        map_skill("dodge", "zhuifeng-liushi"); 
        map_skill("staff","dagou-bang");
           map_skill("strike", "anran-zhang");
      map_skill("parry", "xuantie-jianfa");
      map_skill("sword", "xuantie-jianfa"); 
     prepare_skill("strike", "anran-zhang");


        create_family("��Ĺ��", 4, "����");

        set("inquiry", ([
                "С��Ů" : (: ask_me :),
        ]));
        
	set("count", 1);
        setup();
     	carry_object("/d/quanzhou/npc/obj/xtsword")->wield();
        carry_object("/d/wudang/obj/greyrobe")->wear();

}                                      

string ask_me()
{
	return "�����ֵؿ�����һ�ۣ�������������������𣿡�";
}
       
 
void init()
{
	add_action("do_decide", "decide");  
	add_action("do_wonder", "wonder");
}


int do_wonder(string arg)
{                 
	object ob,me;
	me = this_player();

	if( !arg || arg=="" ) return 0;    
	
	if (query("count") < 1)
                return command("?");
        
        add("count", -1);

	if( arg=="����") 
	{        
		message("vision", YEL"���Ц������û�й���ǰɡ�\n"NOR, me);
		command("say �ҿ������㣬������ľ���ή�͡������(decide)��?");
	 		return 1;      
	}
}

int do_decide()
{        
	object who;
	who = this_player();

        command("bye");
        message_vision("$N���ͷ.$Nֻ��������һ�ᣬ�����Ƽ���㱻����ͳ��˾���ȡ�\n",who);
        who->move("/d/xueshan/foot");
      	who->add("combat_exp", -1000); 
	who->receive_damage("kee", 200);
		return 1;
}

