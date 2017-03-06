#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int ask_xiao();
int ask_me();
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
        set("jiali", 100);
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


        create_family("��Ĺ��", 5, "����");

        set("inquiry", ([
                "С��Ů" : (: ask_xiao :),
                "�����Ķ�" : (: ask_me :),
        ]));

        set("book_count", 1);

        setup();
      carry_object("/d/quanzhou/npc/obj/xtsword")->wield();
        carry_object("/d/wudang/obj/greyrobe")->wear();

}

void attempt_apprentice(object ob)
{
           if ((string)ob->query("gender")=="����")
	{
		command("say ��������֮��,�޷������ɵĹ���! \n");
		return;
	}
        if ((int)ob->query("shen") <100000) {
                command("say �ҹ�Ĺ�����������������ɣ��Ե���Ҫ���ϡ�\n");
                command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
                        "�Ƿ����ò�����\n");
                return;
        }                                                
       if ((int)this_player()->query_temp("marks/��3")!=1){
              command("say ��λ��" + RANK_D->query_respect(ob) + "�ƺ�������Ե! \n");
               return;
       }    
        command("say �ðɣ��Ҿ��������ˡ�\n");
         this_player()->set_temp("marks/��3",0);
        command("recruit " + ob->query("id"));
        if((string)this_player()->query("gender")!="Ů��")
                this_player()->set("title",RED "��Ĺ��" NOR + GRN +"����" NOR);
        else
	        this_player()->set("title",RED "��Ĺ��" NOR + GRN +"Ů����" NOR);
}                               
int ask_xiao()
{    
    say(YEL"��������˵��:�����ҵ�����!����ʶ��? \n"NOR);
      this_player()->set_temp("marks/��1", 1);
return 1;
}
int ask_me()
{      if((int)this_player()->query_temp("marks/��1")){
     say(YEL"�ԴӾ����һ��,����һʮ����,���������Ķ�? \n"NOR);
      command("sigh \n");
        this_player()->set_temp("marks/��1", 0);
       this_player()->set_temp("marks/��2", 1);
     return 1;
} } 
 int accept_object(object ob,object what)
{       
        

     if( (string)what->query("name") == "���" && (int)this_player()->query_temp("marks/��2") && !userp(what)){
                        say("���˵��������Ķ��㵽��?�������������.��?������ƺ�\n"
                            "��Щ����.�㿴���ĳ��,������������!�����:���ھ�,�ұ�\n"
                            "��:��ȵ�.�ѵ��������̵�?�ѵ��������ڻ��ھ���ȵ�?��!\n"
                            "��λ," + RANK_D->query_respect(ob) + ",̫��л����!\n"
                            "��ʲôҪ�󾡹���,�Ҿ���������. \n");
                        this_player()->set_temp("marks/��2",0);
                        this_player()->set_temp("marks/��3", 1);
                        return 1;
                } 
                
                       
       else {command("nod ");
        return 1; }
}
/*void init()
{

        object ob;
        mapping fam;

        ::init();

        ob = this_player();
        if ( (int)ob->query("shen") <0 && ((fam = ob->query("family")) && fam["master_id"] == "song yuanqiao"))
	{
		command("say ����ɱ��Խ����������Ϊ���������������ʦ����\n");
		command("expell "+ ob->query("id"));
	}
}		
       */
/*void heal()
{
        object ob=this_object();

        if (ob->query("eff_qi") < ob->query("max_kee"))
        {
                command("exert heal");
		command("enforce 50");
                return;
        }

        if (ob->query("kee") < ob->query("eff_qi"))
        {
                command("exert recover");
                return;
        }

        if (ob->query("gin") < ob->query("eff_jing"))
                command("exert regenerate");

        return;
}      */
