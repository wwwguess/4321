inherit NPC;
#include <ansi.h>
 
string *make_msg = ({
    HIY "��ޱ΢Ц�Ŀ�����˵����Ҫ��������ѽ!\n\n" NOR,
    HIY "��ޱ���������������ϸ�Ŀ���һ�¡�˵���������Ǹ�����! \n\n" NOR,
    HIY "��ޱ��������Χ��Ҷ��Ū�������ɵ���������\n\n" NOR,
    HIY "�������ã���ޱ�������������ˡ�\n\n" NOR,
    HIY "��ޱ�����õ������ѵݸ��㣬΢Ц˵������! ������! \n\n" NOR,
});

void create()
{
        set_name("����ޱ", ({ "shao-wei","shaowei","wei"  }) );
        set("gender", "Ů��" );
        set("age",18);
        set("long", @TEXT
������ʮ��Ư���������̲�ס���������ۣ���������
���ŵ���������������������ò�������ͷ�����ŵ�
��������ӯ�Ĳ���������Ŷ!
��������ׯ����ֹƼ����Ů��
TEXT
);
       set("class", "dancer");
       set("combat_exp", 200000);
        set_skill("unarmed",70);
        set_skill("dodge", 80);
        set_skill("force",70);
        set_skill("sword",70);
        set_skill("stormdance", 50);
        map_skill("dodge","stormdance");
        set("force", 3000);
        set("max_force", 600);

        set("force_factor", 10);
        set("inquiry", ([
        "��" : "�������Ĳ���!�ұȽ�ϲ����̬�Ļ��\n",
        "������" : "��..!��Ҳϲ���氡! �һ���Ŷ! \n" +
                   "��������Ҫһ������! �������Ұ�����! \n",
        "���" : "��˵��̰�汻���ڽ����ҡ��������������! \n",
        ]));
        create_family("����ׯ",2,"�����");

        setup();
        carry_object("/d/latemoon/obj/clasp")->wear();
        carry_object("/d/latemoon/obj/deer_boot")->wear();
        carry_object("/d/latemoon/obj/skirt2")->wear();
        carry_object("/d/latemoon/obj/bamboo_sword")->wield();

}

void init()
{
       object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }

}
void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
        switch( random(2) ) {
                case 0:
                  say( "��ޱ����΢Ц�����ƵĶ�����ͷ��\n");
                        break;
                case 1:
                  say( "��ޱ����΢Ц������ϸ��������� \n ˵������λ" +
RANK_D->query_respect(ob)
                   + "����ã���ӭ��������ׯ��\n");
        }
}

int accept_object(object who, object ob)
{
     string objname;
     int obweight;
     objname = (string)ob->name();
     obweight = ob->weight();

        if ( objname != "����")  {
           command("smile");
            say ( HIY "��Ҫ�͸��Ұ�?! ��ô����˼!лл�㡣\n" NOR);
           command("blush");
             return 1;
            }
        if( obweight != 300  ) {
	   command("smile");
	   say ( HIC "��������ͶȲ�����û���������ѡ�\n" NOR);
           return 1;
        }
        if( !who->query_temp("moon/����") )  {
          call_out( "make_stage", 2, who, 0 );
            who->set_temp("moon/����", 1);
         } else {
             say (HIY "���Ѿ�������һ����������ѽ! \n" NOR);
             return 1;
          }
          return 1;
}
void make_stage(object who, int stage)
{
     object obj;
     tell_object(who, make_msg[stage]);
     if( ++stage < sizeof(make_msg) ) {
         call_out( "make_stage", 2, who, stage );
         return;
     } else
       obj = new("/d/latemoon/obj/dragonfly");
       obj->move(who);
    return;
}
